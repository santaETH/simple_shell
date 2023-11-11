#include "shell.h"

/**
 * Display the shell prompt.
 */
void display_prompt() {
    printing("SHELL$ ");
    fflush(stdout);
}

/**
 * Read a line of input from the user.
 *
 * @param buffer: The buffer to store the input.
 * @param max_length: The maximum length of the input.
 * @return: Returns the number of characters read.
 */
int user_input(char *buffer, int len) {
    return fgets(buffer, len, stdin) == NULL ? 0 : strlen(buffer);
}

/**
 * Execute a command.
 *
 * @param command: The command to execute.
 * @return: Returns 0 if successful, -1 on failure.
 */
int execute_command(const char *command) {
    if (access(command, X_OK) == 0) {
        pid_t child_pid;
        int status;

        child_pid = fork();

        if (child_pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0) {
            char *args[2];
            args[0] = strdup(command);
            args[1] = NULL;
            if (execve(args[0], args, NULL) == -1) {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        } else {
            waitpid(child_pid, &status, 0);
            if (WIFEXITED(status)) {
                printing("Child exited with status %d\n", WEXITSTATUS(status));
            }
        }

        return 0;
    } else {
        fprintf(stderr, "Command not found: %s\n", command);
        return -1;
    }
}

int main() {
    char input[MAXIMUM_INPUT];

    while (1) {
        display_prompt();

        if (user_input(input, sizeof(input)) == 0) {
            printing("\n");
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (execute_command(input) == -1) {
            fprintf(stderr, "Command not found: %s\n", input);
        }
    }

    return 0;
}

