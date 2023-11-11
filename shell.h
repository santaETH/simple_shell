#ifndef MAIN_HEADER_FILE
#define MAIN_HEADER_FILE

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
#include <stdbool.h>
#include <stdarg.h>

void custom_print(const char *str);
void handle_error(pid_t pid);
bool check_file_status(char *pathname, struct stat *statbuf);
int _execute(char *arguments, struct stat *statbuf, char **envp);
char **tokenization(char *src, const char *delimiter);
char **split_string(char *str, const char *delimiter, int *argc);
void free_tokens(char **tokens);

#endif

<<<<<<< HEAD
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
=======
>>>>>>> 04ffb75a9b3ca42f83d543ef5439fab883d67a43
