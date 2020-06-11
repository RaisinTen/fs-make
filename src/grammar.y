%{
#include <stdio.h>
#include <stdlib.h>

#include "node.hpp"
#include "errors.hpp"

extern int yylex(); // main entry point for flex

extern struct Node* root; // holds the entire AST

%}

/*
 * this union stores all the types
 * allowed for the symbols in the
 * grammar to be parsed
 */
%union
{
    char cval;
    char* sval;
    struct Node* nval;
}

/* declaration of terminal symbols */
%token<cval> COMMA COLON LBRACE RBRACE
%token<sval> STR

/* declaration of non-terminal symbols */
%type<nval> all dir files collection file

/*
 * here are the production rules
 * of the grammar, each of the form:

non-terminal
: <list of terminals and non-terminals>     { // code to form this particular part of the AST }
| <list of terminals and non-terminals>     { // code to form this particular part of the AST }
...
;

 * In each production, the part before the colon (:)
 * is accessed using the $$ symbol and each symbol
 * of the list of terminals are accessed like this:
 * $1, $2, $3, ...
 * in their respective order of appearance
 */

%%
all
: dir                       { $$ = $1; root = $$; }
;

dir
: LBRACE files RBRACE       { $$ = (struct Node*) malloc(sizeof(struct Node)); *($$) = (struct Node) {.name = NULL, .next = NULL, .children = $2}; }
| file                      { $$ = (struct Node*) malloc(sizeof(struct Node)); *($$) = (struct Node) {.name = NULL, .next = NULL, .children = $1}; }
;

files
:                           { $$ = NULL; }
| collection                { $$ = $1; }
;

collection
: file                      { $$ = $1; }
| file COMMA collection     { $$ = $1; $$->next = $3; }
;

file
: STR                       { $$ = (struct Node*) malloc(sizeof(struct Node)); *($$) = (struct Node) {.name = $1, .next = NULL, .children = NULL}; }
| STR COLON dir             { $$ = (struct Node*) malloc(sizeof(struct Node)); *($$) = (struct Node) {.name = $1, .next = NULL, .children = $3}; }
;
%%
