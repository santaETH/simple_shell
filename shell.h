#ifndef _SHELL_H_
#define _SHELL_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdarg.h>
#include <ctype.h>

/*macros*/
#define PATH_MAX_LENGTH 4096
#define PATH_SEPARATOR ":"
#define PROMPT "$ "
#define MAX_TOKENS 1024
#define BUFFER_SIZE 1024

void terminal_prompt(void);
char *get_inputs(void);
void freeing_recent_arg(void);
int prompt_execution(char **argv);
void *get_line(void);
void free_error(char **argv, char *arguments);
void free_tokens(char **pointer);
void free_path(void);
int builtins_check(char **arguments);
int execute_buitlin(char *cmd, char **args);
void man_help(void);
void terminal_exit(char **args);
void cd_implementation(char **arguments);
int setenv_command(char **arguments);
int unsetenv_command(char **arguments);
int environment_variables(void);
int reset_shell_display(char **args);
void handle_sigint(int signal);
void handle_sigquit(int signal);
void handle_sigstp(int signal);
int _strlen(const char *str);
int _strcmp(const char *str1, const char *str2);
int _strncmp(const char *str1, const char *str2, size_t range);
char *_strstr(char *haystack, char *needle);
char *_strchr(char *str, char n);
void handle_variable(char *command);
void _puts(char *str);
void _outputerr(char *error_message);
int execute(char **args);
char *_strcpy(char *destination, char *source);
char *_strcat(char *destination, const char *source);
char *_strdup(const char *string);
int _putchar(char);
unsigned int _strspn(char *c, char *accept);
int _atoi(const char *s);
char *_memset(char *a, char b, unsigned int n);
char *_memcpy(char *destination, char *source, unsigned int n);
void *_realloc(void *init, unsigned int old_buffer, unsigned int new_buffer);
void *_calloc(unsigned int size, unsigned int len);
char *_getenv(const char *name);
char **tokenization(char *string, const char *delimiter);
char **input_tokenization(char *user_command);
char *get_path_env(void);
char *locate_command(char *input);

#endif
