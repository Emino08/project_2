/* CMSC 430 Compiler Theory and Design
   Project 2
   Spring 2023

   This file contains the lexical analyzer for the language.
*/

%{
#include <string>
#include <limits.h>
#include <cctype>

using namespace std;

#include "listing.h"
#include "parser.tab.h"

%}

%option noyywrap

ws		[ \t\r]+
comment		\/\/.*\n
line		[\n]
id		[A-Za-z][A-Za-z0-9]*
digit		[0-9]
int		{digit}+
real		{digit}+\.{digit}*([Ee][+-]?{digit}+)?|\.[0-9]+([Ee][+-]?{digit}+)?
char		\'[^'\n]\'
hex             \#[A-Fa-f0-9]+

%%

{ws}		{ /* No action and no return */ }
{comment}	{ nextLine(); }
{line}		{ nextLine(); }

"+"		{ return(ADDOP); }
"-"		{ return(ADDOP); }
"*"		{ return(MULOP); }
"/"		{ return(MULOP); }
"%"             { return(MODOP); }
"^"             { return(EXPOP); }
"~"             { return(NEGOP); }
"!"             { return(NOTOP); }
"<"		{ return(RELOP); }
">"		{ return(RELOP); }
"<="	        { return(RELOP); }
">="	        { return(RELOP); }
"="		{ return(RELOP); }
"<>"	        { return(RELOP); }
"&"		{ return(ANDOP); }
"|"		{ return(OROP); }
"=>"	        { return(ARROW); }

"("		{ return('('); }
")"		{ return(')'); }
","		{ return(','); }
":"		{ return(':'); }
";"		{ return(';'); }

begin		{ return(BEGIN_); }
boolean		{ return(BOOLEAN); }
case		{ return(CASE); }
character	{ return(CHARACTER); }
else		{ return(ELSE); }
elsif		{ return(ELSIF); }
end		{ return(END); }
endif		{ return(ENDIF); }
endswitch	{ return(ENDSWITCH); }
function	{ return(FUNCTION); }
if		{ return(IF); }
integer		{ return(INTEGER); }
is		{ return(IS); }
list		{ return(LIST); }
of		{ return(OF); }
others		{ return(OTHERS); }
real		{ return(REAL); }
returns		{ return(RETURNS); }
switch		{ return(SWITCH); }
then		{ return(THEN); }
when		{ return(WHEN); }
fold		{ return(FOLD); }
left		{ return(LEFT); }
right		{ return(RIGHT); }
endfold		{ return(ENDFOLD); }

{id}		{ yylval.iden = strdup(yytext); return(IDENTIFIER); }
{int}		{ yylval.text = strdup(yytext); return(INT_LITERAL); }
{real}		{ yylval.text = strdup(yytext); return(REAL_LITERAL); }
{char}		{ yylval.text = strdup(yytext); return(CHAR_LITERAL); }
{hex}		{ yylval.text = strdup(yytext); return(INT_LITERAL); }

.		{ appendError(LEXICAL, yytext); }

%%