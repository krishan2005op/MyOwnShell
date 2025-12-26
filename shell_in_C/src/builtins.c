#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "builtins.h"
#include <unistd.h>
#include <fcntl.h>

static void open_url(const char *url) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child: detach from terminal
        int fd = open("/dev/null", O_RDWR);
        if (fd != -1) {
            dup2(fd, STDIN_FILENO);
            dup2(fd, STDOUT_FILENO);
            dup2(fd, STDERR_FILENO);
            close(fd);
        }

        execlp("powershell.exe", "powershell.exe",
               "-NoProfile",
               "Start-Process", url,
               NULL);

        _exit(1); // use _exit in child
    }
}

static void search_query(char **argv, const char *base_url) {
    char url[1024];
    snprintf(url, sizeof(url), "%s", base_url);

    for (int i = 1; argv[i]; i++) {
        strcat(url, argv[i]);
        strcat(url, "+");
    }

    open_url(url);
}

int handle_builtin(char **argv) {
    if (argv[0] == NULL)
        return 1;

    // exit
    if (strcmp(argv[0], "exit") == 0) {
        printf("Exiting shell...\n");
        exit(0);
    }

    // cd
    if (strcmp(argv[0], "cd") == 0) {
        if (argv[1] == NULL) {
            fprintf(stderr, "cd: missing argument\n");
        } else {
            if (chdir(argv[1]) != 0) {
                perror("cd");
            }
        }
        return 1;
    }

    // help
    if (strcmp(argv[0], "help") == 0) {
        printf("Built-in commands:\n");
        printf("  cd <dir>   Change directory\n");
        printf("  exit       Exit the shell\n");
        printf("  help       Show this help\n");
        return 1;
    }
    // App launcher
    if (strcmp(argv[0], "google") == 0) {
        open_url("https://www.google.com");
        return 1;
    }

    if (strcmp(argv[0], "code") == 0) {
        if (fork() == 0) {
            execlp("code", "code", NULL);
            exit(1);
        }
        return 1;
    }
    // search
if (strcmp(argv[0], "search") == 0) {
    search_query(argv, "https://www.google.com/search?q=");
    return 1;
}

// yt
if (strcmp(argv[0], "yt") == 0) {
    search_query(argv, "https://www.youtube.com/results?search_query=");
    return 1;
}

// gh
if (strcmp(argv[0], "gh") == 0) {
    search_query(argv, "https://github.com/search?q=");
    return 1;
}

// so
if (strcmp(argv[0], "so") == 0) {
    search_query(argv, "https://stackoverflow.com/search?q=");
    return 1;
}


    return 0; // not a builtin
}
