#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

#define MAX_TOKENS 64

char **parse_command(char *line) {
    char **tokens = malloc(sizeof(char *) * MAX_TOKENS);
    if (!tokens) return NULL;

    int i = 0;
    char *token = strtok(line, " \t\n");

    while (token && i < MAX_TOKENS - 1) {
        tokens[i++] = strdup(token);
        token = strtok(NULL, " \t\n");
    }

    tokens[i] = NULL;
    return tokens;
}

void free_tokens(char **tokens) {
    for (int i = 0; tokens[i]; i++) {
        free(tokens[i]);
    }
    free(tokens);
}
