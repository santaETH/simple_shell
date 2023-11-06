#ifndef MAIN_HEADER_FILE
#define MAIN_HEADER_FILE

#define MAXIMUM_INPUT 100

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

void printing(const char *format, ...);
void show_prompt(void);
char **tokenized_input(char *user_input);
char **tokenization(char *src, const char *delimeter);

#endif

