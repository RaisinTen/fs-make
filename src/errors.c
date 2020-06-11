#include <stdlib.h>
#include <stdio.h>

#include "errors.hpp"
#include "util.hpp"

void yyerror(const char* msg)
{
    log_stderr(msg);
    exit(EXIT_FAILURE);
}
