#include "header.h"

/**
 * token_count - count number of tokens
 * @str: string to tokenize
 *
 * Return: Number of tokens
 */

int token_count(char *str)
{
	int count = 0;
	char *token;
	char *duplicate;

	duplicate = _strdup(str);

	token = strtok(duplicate, " ");
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " ");
	}
	free(duplicate);
	return (count);
}


/**
 * ret_array - for each word of a string received from getline
 * @string: breaks string into tokens
 *
 * Return: pointer to pointer of arrays of strings
 */

char **ret_array(char *string)
{
	int i = 0;
	int num_token = 0;
	char **array;
	char *token;

	num_token = token_count(string);
	array = malloc((sizeof(char *) * (num_token + 1)));
	token = strtok(string, " ");
	while (token != NULL)
	{
/*		write(STDOUT_FILENO, token, strlen(token));
		write(STDOUT_FILENO, "\n", 1);
*/		array[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	array[i] = NULL;
	return (array);
}
