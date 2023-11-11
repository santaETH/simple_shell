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
