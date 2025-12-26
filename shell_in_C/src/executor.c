#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "executor.h"

void execute_external(char **argv) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        execvp(argv[0], argv);
        perror("execvp failed");
        exit(EXIT_FAILURE);
    } 
    else if (pid > 0) {
        // Parent process
        waitpid(pid, NULL, 0);
    } 
    else {
        perror("fork failed");
    }
}
