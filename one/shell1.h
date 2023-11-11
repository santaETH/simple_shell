#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

#define MAXIMUM_INPUT 1024

/* tokenization.c */
char **tokenization(char *src, const char *delimiter);

/* execute_command.c */
int execute_command(char **args, int *status);

/* printing.c */
void printing(const char *format, ...);

/* Utility functions (implement these) */
void free_tokens(char **tokens);
char *_strdup(const char *str);
void _free(char *ptr);
void *_realloc(void *ptr, size_t old_size, size_t new_size);

#endif /* SHELL_H */

