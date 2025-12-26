#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
#include "parser.h"
#include "executor.h"
#include "builtins.h"

int main() {
    char *line;
    char **tokens;

    while (1) {
        printf("mysh> ");
        fflush(stdout);

        line = read_input();
        if (line == NULL) {
            printf("\n");
            break;
        }

        tokens = parse_command(line);

        if (tokens[0] != NULL) {
            // First check built-ins
            if (!handle_builtin(tokens)) {
                // If not builtin, execute externally
                execute_external(tokens);
            }
        }

        free_tokens(tokens);
        free(line);
    }

    return 0;
}
