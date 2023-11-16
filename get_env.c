#include "shell.h"

/**
 * _getenv - function to find environement
 * @genv: environment variable
 * Return: 0
 */
void _getenv(char **genv)
{
	for (; *genv; genv++)
	{
		write(STDOUT_FILENO, *genv, strlen(*genv));
		write(STDOUT_FILENO, "\n", 1);
	}
}

