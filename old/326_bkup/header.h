#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

extern char **environ;

char *_getenv(const char *name);
char **print_dir(char *str);
char *append(char *path, char *name);
char *is_exec(char **path, char *name);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int token_count(char *str);
char **ret_array(char *string);

#endif
