#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

int yylex(); // main entry point for flex, required by bison to invoke flex
int yyparse(); // required by main to build the AST (Abstract Syntax Tree)
struct Node* root; // holds the entire AST

#ifdef __cplusplus
}
#endif
