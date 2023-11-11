#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_ARGS 100

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
