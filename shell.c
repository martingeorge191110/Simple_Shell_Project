#include "shell.h"

/**
 * handle_build_in - Function to handle build in commands
 * @cmd_arr: array of commands
 * @argv: Program name
 * @env: environment variables
 *
 * Return: (status)
 */

int handle_build_in(char **cmd_arr, const char *argv, struct env_cpy **env)
{
	int status, i;
	built_in arr[] = {
		{"exit", exit_shell}, {"env", print_env},
		{"setenv", set_env},
		{"unsetenv", un_set_env},
		{NULL, NULL}
	};

	for (i = 0; arr[i].cmd; i++)
	{
		if (str_cmp(cmd_arr[0], arr[i].cmd, str_len(arr[i].cmd) + 1) == 0)
		{
			status = arr[i].f(cmd_arr, env, argv);
			if (status == -1)
			{
				full_error_handling(cmd_arr[0], argv);
				command_free(cmd_arr);
				free_env_list(env);
				if (!isatty(STDIN_FILENO))
					exit(2);
			}
			return (status);
		}
	}
	return (0);
}

/**
 * handle_ctrl_c - Function to handle ctrl + c
 * @st: interger to be avoided
 */

void handle_ctrl_c(int st)
{
	(void)st;
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "./hsh: 1: No such file or directory", 35);
	write(STDOUT_FILENO, "\n", 1);
	print_prompt();
}

/**
 * main - Entry Point
 * @argc: argument counter
 * @argv: argument value
 * @env: environment vairiable
 *
 * Return: (0)
 */

int main(int argc, char *argv[], char **env)
{
	char *buffer = NULL;
	int builtInStat, cdStat;
	char **globalCmdArr;
	env_cpy *globalEnvCpy;

	globalEnvCpy = initialize_env(env);
	if (globalEnvCpy == NULL)
	{
		perror("Failed to initialize environment");
		exit(EXIT_FAILURE);
	}
	(void)argc;
		signal(SIGINT, handle_ctrl_c);
	while (1)
	{
		cdStat = 1;
		print_prompt();
		buffer = get_line(&globalEnvCpy);
		if (!buffer || !buffer[0])
		{
			free(buffer);
			continue;
		}
		globalCmdArr = get_command(buffer, &globalEnvCpy);
		free(buffer);
		buffer = NULL;
		if (!globalCmdArr || !globalCmdArr[0])
			continue;

		builtInStat = handle_build_in(globalCmdArr, argv[0], &globalEnvCpy);
		if (builtInStat == 0)
			cdStat = cd_funct(globalCmdArr, globalEnvCpy);

		if (cdStat == 0)
			exec_command(globalCmdArr, env, argv[0], globalEnvCpy);

		command_free(globalCmdArr);
		globalCmdArr = NULL;
	}
	return (0);
}
