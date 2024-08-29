#include "shell.h"

/**
 * get_command - Function to get the command
 *						and split it in array of strings
 * @command: which is the pinter of string get by user
 * @env: pointer to environment variables list
 *
 * Return: (commandArray)
 */

char **get_command(const char *command, env_cpy **env)
{
	char *token, *cmdCpy, **commandArray;
	int i = 0, arrSize;
	const char *delim = " \t\n";

	if (!command)
		return (0);

	arrSize = command_counter(command);
	if (arrSize == 0)
		return (NULL);

	cmdCpy = str_dup(command);
	commandArray = malloc(sizeof(char *) * (arrSize + 1));
	if (!commandArray)
	{
		perror("malloc");
		free(cmdCpy);
		free_env_list(env);
		exit(EXIT_FAILURE);
	}
	token = strtok(cmdCpy, delim);
	while (token)
	{
		commandArray[i] = malloc(sizeof(char) * (str_len(token) + 1));
		if (!commandArray[i])
		{
			perror("malloc");
			command_free(commandArray);
			free_env_list(env);
			free_variadic(2, cmdCpy, token);
			exit(EXIT_FAILURE);
		}
		str_cpy(commandArray[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	commandArray[i] = NULL;
	free_variadic(2, cmdCpy, token);
	return (commandArray);
}
