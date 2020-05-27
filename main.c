#include <stdio.h>
#include <string.h>

#include "commons.h"
#include "node.h"
#include "pretty_print.h"
#include "script_generator.h"

// holds the entire AST (Abstract Syntax Tree)
struct Node* root;

int main(int argc, char* argv[])
{
    const char* Usage = 
        "Usage: " TARGET " infile outfile\n"
        "   infile: input file\n"
        "   outfile: output file\n"
        ;

    if(argc == 2)
    {
        if(strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)
        {
            puts(TARGET " " VERSION);
        }
        else if(strcmp(argv[1], "--help") == 0)
        {
            puts(TARGET " " VERSION);
            puts(Usage);
        }
        else
        {
            fprintf(stderr, "invalid argument: %s\n", argv[1]);
            fputs(Usage, stderr);

            return 1;
        }

        return 0;
    }

    if(argc != 3)
    {
        fputs("invalid arguments:", stderr);
        for(int i = 1; i < argc; ++i)
        {
            fprintf(stderr, " %s", argv[i]);
        }
        fputs("\n", stderr);
        fputs(Usage, stderr);

        return 1;
    }

    if(freopen(argv[1], "r", stdin) == NULL)
    {
        fprintf
            (
                stderr,
                "%s: infile couldn't be open",
                argv[1]
            );

        return 1;
    }

    if(freopen(argv[2], "w", stdout) == NULL)
    {
        fprintf
            (
                stderr,
                "%s: outfile couldn't be open",
                argv[2]
            );

        return 1;
    }

    yyparse();

    generate_script(root);
    // pretty_print_element(root, 0);
    clear(root);

    return 0;
}
