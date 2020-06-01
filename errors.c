#include <stdlib.h>
#include <stdio.h>

#include "commons.h"
#include "errors.h"
#include "util.h"

void yyerror(const char* msg)
{
    log_stderr(msg);
    exit(EXIT_FAILURE);
}
