#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MAL_HISTORY_FILENAME ".mal-history"

char* repl_read(void);
char* repl_eval(char*);
void repl_print(char*);

int main(int argc, char* argv[])
{
    using_history();
    read_history(MAL_HISTORY_FILENAME);

    while (true)
    {
        char* input = NULL, *output = NULL;

        input = repl_read();
        if (input == NULL) break;
        add_history(input);

        output = repl_eval(input);
        repl_print(output);

        free(input);
        input = NULL;

        free(output);
        output = NULL;
    }

    write_history(MAL_HISTORY_FILENAME);

    return EXIT_SUCCESS;
}

char* repl_read(void)
{
    return readline("user> ");
}

char* repl_eval(char* program)
{
    return strdup(program);
}

void repl_print(char* output)
{
    printf("%s\n", output);
}