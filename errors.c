#include <stdlib.h>
#include <stdio.h>

#include "commons.h"
#include "errors.h"

void yyerror(const char* msg)
{
    fputs(msg, stderr);
    exit(EXIT_FAILURE);
}
