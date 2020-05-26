%{
#include <stdio.h>

#include "commons.h"
#include "util.h"
#include "errors.h"
#include "grammar.tab.h"
%}

%option noyywrap
%option noinput
%option nounput

str         \"(\\.|[^"\\])*\" 
comma       ,
colon       :
lbrace      \{
rbrace      \}
whitespace  [ \t\n\r]

%%
{whitespace}    ;
{str}           { yylval.sval = strdup(yytext); strip_quotes(yylval.sval); return STR; }
{lbrace}        { return LBRACE; }
{rbrace}        { return RBRACE; }
{colon}         { return COLON; }
{comma}         { return COMMA; }
.               { char msg[64]; sprintf(msg, "Unknown character: %c", yytext[0]); yyerror(msg); }
%%
