#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * count number of tokens
 */

int token_count(char *str)
{
	int count = 0;
	char *token;

	token = strtok(str, " ");
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " ");
	}
	return (count);
}


/**
 * returns array for each word of a string received from getline
 *
 */

char **ret_array(char *string)
{
	int i = 0;
	int num_token = 0;
	char **array;
	char *token;

	num_token = token_count(string);
	array = malloc(sizeof(char *) * num_token);
	token = strtok(string," ");
	while (token != NULL)
	{
/*		write(STDOUT_FILENO, token, strlen(token));
		write(STDOUT_FILENO, "\n", 1);
*/		array[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	return (array);
}

/*
 * getline a string, breaks string into tokens
 */

int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	size_t characters;
	int num_tokens = 0;
	char *token;
	int i, j = 0;
	char **array;

	write(STDOUT_FILENO, "$ ", 2);
	characters = getline(&buffer, &bufsize, stdin);
	while (*(buffer + j) != '\n')
		j++;
	*(buffer + j) ='\0';

/*
	token = strtok(buffer," ");
	while (token != NULL)
	{
		write(STDOUT_FILENO, token, strlen(token));
		if (*token == '\n')
			break;

		write(STDOUT_FILENO, "\n", 1);
		token = strtok(NULL, " ");
	}
*/

/*	write(STDOUT_FILENO, buffer, bufsize); */

	num_tokens = token_count(buffer);
	array = ret_array(buffer);
	printf("%d\n", num_tokens);
	for (i = 0; i < num_tokens - 1; i++)
	{
		printf("%s\n", array[i]);
	}
	free(array);
	free(buffer);
	return (0);
}
