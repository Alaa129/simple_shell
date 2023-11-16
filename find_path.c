#include "shell.h"

/**
 * find_path - main simple shell function
 * @cmd: number of arguments
 * Return: 0
 */
char *find_path(const char *cmd)
{
	char full_location[1024];
	char *location_cpy;
	char *location;
	char *tkn;

	location = getenv("PATH");

	if (location == NULL)
	{
		return (NULL);
	}

	location_cpy = strdup(location);
	if (location_cpy == NULL)
	{
		perror("strdup");
		return (NULL);
	}

	tkn = strtok(location_cpy, ":");
	while (tkn != NULL)
	{
		strcpy(full_location, tkn);
		strcat(full_location, "/");
		strcat(full_location, cmd);

		if (access(full_location, X_OK) == 0)
		{
			free(location_cpy);
			return (strdup(full_location));
		}

		tkn = strtok(NULL, ":");
	}

	free(location_cpy);
	return (NULL);
}

