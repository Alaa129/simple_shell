#ifndef SHELL_H
#define SHELL_H
/** #define BUFFER_BYTES 1024 */
#define BUFFER 512

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int _builtins_cmds(char *args[], char **env); /**/
/** char *get_env_value(const char *name); */
int exec_command(char *argus[], char **environ, char *argv[], int cd_count);
void showprompt(void); /**/
void _getenv(char **genv); /**/
char *find_path(const char *cmd); /**/
int _strcmp(char *string1, char *string2); /**/
int _strlen(char *len); /**/

#endif
