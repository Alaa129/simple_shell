#include "shell.h"

/**
 * showprompt - prompt of simple shell
 * Return: 0
 */
void showprompt(void)
{
	if (isatty(STDIN_FILENO))
		printf("$ ");
}

/**
 * _builtins_cmds - main simple shell function
 * @args: number of arguments
 * @env: env
 * Return: 0
 */
int _builtins_cmds(char *args[], char **env)
{
	if (_strcmp(args[0], "env") == 0)
	{
		_getenv(env);
		return (1);
	}
else if (_strcmp(args[0], "exit") == 0)
{
exit(EXIT_SUCCESS);
}
return (0);
}

/**
 * exec_command - function to execute command
 * @argus: arguments to be executed
 * @environ: get environement
 * @argv: argv
 * @cd_count: command counter
 * Return: 0
 */
int exec_command(char *argus[], char **environ, char *argv[], int cd_count)
{
	pid_t c_pid;
	int child = 0, action = 0;

	c_pid = fork();
	if (c_pid == -1)
	{
		perror("child_pid");
		exit(EXIT_FAILURE);
	}
	else if (c_pid == 0)
	{
		char *track = NULL;

		if ((argus[0][0] != '/' || argus[0][0] != '.'))
			track = find_path(argus[0]);
		if (track == NULL)
			track = argus[0];
		if (execve(track, argus, environ) == -1)
			child = 127;

		fprintf(stderr, "%s: %d: %s: not found\n", argv[0], cd_count, argus[0]);
	}
	else
	{
		waitpid(c_pid, &action, 0);

		if (WIFEXITED(action))
			child = WEXITSTATUS(action);
		else if (WIFSIGNALED(action))
			child = WTERMSIG(action);
	}
	return (child);
}

/**
 * main - main function of simple shell
 * @argc: counter of arguments
 * @argv: commant line arguments
 * @environ: env
 * Return: 0
 */
int main(int argc, char *argv[], char **environ)
{
	char command[BUFFER];
	char *tkn;
	char *argument[BUFFER];
	int log = 0, cmd_log = 0, result = 0, n = 0;
	size_t in_length;

	(void)argc;
	for (; ;)
	{
		showprompt();
		if (fgets(command, sizeof(command), stdin) == NULL)
			break;
		cmd_log++;
		in_length = _strlen(command);

		if (in_length > 0 && command[in_length - 1] == '\n')
			command[in_length - 1] = '\0';
		tkn = strtok(command, " ");
		while (tkn != NULL)
		{
			argument[log++] = tkn;
			tkn = strtok(NULL, " ");
		}
		argument[log] = NULL;
		if (log > 0)
		{
			if (_builtins_cmds(argument, environ) == 1)
				continue;
			if (_strcmp(argument[0], "exit") == 0)
				break;
			result = exec_command(argument, environ, argv, cmd_log);

			for (n = 0; n < BUFFER; n++)
				argument[n] = NULL;
		}
		log = 0;
	}
	return (result);
}

