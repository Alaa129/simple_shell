#include "shell.h"

/**
 * _strlen - function to find string length
 * @len: tring to find his 
 * Return: string length
 */
int _strlen(char *len)
{
	int a = 0;

	while (*len != '\0')
	{
		len++;
		a++;
	}
	return (a);
}

/**
 * _strcmp - compare between 2 strings
 * @string1: char strr1 pointer
 * @string2: char strr2 pointer
 * Return: 0
 */
int _strcmp(char *string1, char *string2)
{
	char result = strcmp(string1, string2);

	return (result);
}

