#include <stdio.h>
#include <string.h>

#include "commons.h"
#include "util.h"
#include "node.h"
#include "pretty_print.h"
#include "script_generator.h"

// holds the entire AST (Abstract Syntax Tree)
struct Node* root;
FILE* infile;
FILE* outfile;

extern FILE* yyin;

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
            log_stdout(TARGET " " VERSION "\n");
        }
        else if(strcmp(argv[1], "--help") == 0)
        {
            log_stdout(TARGET " " VERSION "\n");
            log_stdout(Usage);
        }
        else
        {
            log_stderr("invalid argument: %s\n", argv[1]);
            log_stderr(Usage);

            return 1;
        }

        return 0;
    }

    if(argc != 3)
    {
        log_stderr("invalid arguments:");
        for(int i = 1; i < argc; ++i)
        {
            log_stderr(" %s", argv[i]);
        }
        log_stderr("\n");
        log_stdout(Usage);

        return 1;
    }

    if((infile = fopen(argv[1], "r")) == NULL)
    {
        log_stderr("%s: infile couldn't be open", argv[1]);
        return 1;
    }

    if((outfile = fopen(argv[2], "w")) == NULL)
    {
        log_stderr("%s: outfile couldn't be open", argv[2]);
        return 1;
    }

    yyin = infile;
    yyparse();

    generate_script(root);

#if 0
    pretty_print_element(root, 0);
    log_stdout("\n");
#endif

    clear(root);

    fclose(infile);
    fclose(outfile);

    return 0;
}
