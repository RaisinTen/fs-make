#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

extern int yylex(); // main entry point for flex, required by bison to invoke flex
extern int yyparse(); // required by main to build the AST (Abstract Syntax Tree)

extern struct Node* root; // holds the entire AST

#include <stdio.h>

#ifdef __cplusplus
}
#endif
