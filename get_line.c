#include "shell.h"

/**
 * get_line - read user input line
 *
 * Return: 0
*/

char *get_line(env_cpy **env)
{
	char *str = NULL;
	size_t num = 0;
	ssize_t bytes;

	bytes = getline(&str, &num, stdin);
	if (bytes == EOF)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		free_env_list(env);
		free(str);
		exit(EXIT_SUCCESS);
	}

	if (bytes <= 0 || str[0] == '\n')
	{
		free(str);
		return (NULL);
	}

	return (str);
}
