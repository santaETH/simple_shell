#ifndef SHELL_H_
#define SHELL_H_

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <limits.h>
#include <errno.h>
#include <unistd.h>
#include <stdarg.h>

#define MAX_ARGS 100
#define MAX_PATH_LENGTH 1024
#define MAX_COMMAND_LENGTH 1000
#define MAX_INPUT_LENGTH 1024
#define COMMAND_LENGTH 100
#define BUFFER_SIZE 1024

extern char **environ;

void exit_sh(void);
ssize_t _read(char *buf, int fd, size_t *n);
ssize_t _getlne(char **line, size_t *n, int fd);
char *n_parse(void);
char **tokenization(char *line, char *del);
char **ma_input(void);
char *_strtok(char *str, const char *delim);
long int _strlen(const char *str);
char *search(char **neww, char *str, const char *delim);
void _execve(const char *pathname, char *const argv[], char *const envp[]);

#endif /* SHELL_H */
