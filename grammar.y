%{
#include <stdio.h>
#include <stdlib.h>

#include "commons.h"
#include "node.h"
#include "errors.h"
%}

%union
{
    char cval;
    char* sval;
    struct Node* nval;
}

%token<ival> NUM
%token<cval> COMMA COLON LBRACE RBRACE
%token<sval> STR

%type<nval> all dir files collection file

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
