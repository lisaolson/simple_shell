#include "header.h"

/**
 * is_exec - checks if file exists and is executable
 * @path: takes in matrix of strings
 * @name: string to check access against
 *
 * Return: executable file, original string, or error
*/
char *is_exec(char **path, char *name)
{
	char *str;

	if (name[0] == '\0')
		return (name);
	while (*path)
	{
		str = append(*path, name);
		if (access(name, F_OK) == 0 && access(name, X_OK) == 0)
			return (name);
		if (access(str, F_OK) == 0 && access(str, X_OK) == 0)
			return (str);
		path++;
	}
	return ("File doesn't exist or it hit null");
}
