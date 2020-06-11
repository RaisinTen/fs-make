%{
#include <stdio.h>

#include "commons.hpp"
#include "util.hpp"
#include "errors.hpp"
#include "grammar.tab.h"
%}

%option noyywrap
%option noinput
%option nounput

/* regular expressions for allowed tokens */

str         \"(\\.|[^"\\])*\" 
/*
 * strings can be any
 * sequence of characters
 * with the exception that
 * backslashes(\) and
 * double quotes (")
 * need to be escaped by
 * placing a backslash
 * before them
 */

comma       ,
colon       :

lbrace      \{
rbrace      \}

whitespace  [ \t\n\r]
/*
 * whitespace is ignored
 * by the parser, it
 * consists of:
 *  * space
 *  * tabs
 *  * newlines
 *  * carriage returns
 */

/* here, we set the rules for what flex does
 * when it encounters each symbol in the form:
{symbol-name}   { // handle errors or fill in yylval with the data and return the symbol type }
 */

%%
{whitespace}    ;
{str}           { yylval.sval = strdup(yytext); strip_quotes(yylval.sval); return STR; }
{lbrace}        { return LBRACE; }
{rbrace}        { return RBRACE; }
{colon}         { return COLON; }
{comma}         { return COMMA; }
.               { char msg[64]; sprintf(msg, "Unknown character: %c", yytext[0]); yyerror(msg); }
%%
