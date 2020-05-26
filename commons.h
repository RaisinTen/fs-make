#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

int yylex();
int yyparse();
struct Node* root;

#ifdef __cplusplus
}
#endif
