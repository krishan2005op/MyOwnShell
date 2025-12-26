#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "shell.h"

char *read_input(void) {
    char *line = NULL;
    size_t len = 0;

    ssize_t nread = getline(&line, &len, stdin);
    if (nread < 0) {
        free(line);
        return NULL;
    }

    return line;
}
