/* CMSC 430 Compiler Theory and Design
   Project 2
   Spring 2023

   This file contains the grammar for our language.
*/

%{

#include <string>
#include <vector>
#include <map>

using namespace std;

#include "listing.h"

int yylex();
void yyerror(const char* message);

%}

%union
{
	char* iden;
	char* text;
}

%token <iden> IDENTIFIER
%token <text> INT_LITERAL REAL_LITERAL CHAR_LITERAL 

%token ADDOP MULOP RELOP ANDOP OROP NOTOP EXPOP MODOP NEGOP
%token BEGIN_ BOOLEAN CASE CHARACTER ELSE ELSIF END ENDFILE ENDIF ENDSWITCH
%token FUNCTION IF INTEGER IS LIST MAIN OF OTHERS REAL RETURNS
%token SWITCH THEN WHEN ARROW FOLD LEFT RIGHT ENDFOLD

%%

function:
    function_header variables body ;

function_header:
    FUNCTION IDENTIFIER optional_parameters RETURNS type ';' |
    FUNCTION IDENTIFIER error ';' 
    { yyerror("Syntax Error"); } ;

optional_parameters:
    /* empty */ |
    parameters ;

parameters:
    parameter |
    parameters ',' parameter ;

parameter:
    IDENTIFIER ':' type ;

variables:
    /* empty */ |
    variables variable ;

variable:
    IDENTIFIER ':' type IS statement ';' |
    IDENTIFIER ':' LIST OF type IS list ';' |
    IDENTIFIER error ';'
    { yyerror("Syntax Error"); } ;

list:
    '(' expressions ')' ;

expressions:
    expression |
    expressions ',' expression;

type:
    INTEGER | 
    REAL | 
    CHARACTER ;

body:
    BEGIN_ statement END ';' ;

statement:
    expression ';' |
    WHEN condition ',' expression ':' expression ';' |
    switch_statement |
    if_statement |
    fold_statement ;

switch_statement:
    SWITCH expression IS cases OTHERS ARROW statement ENDSWITCH ';' ;

cases:
    case |
    cases case ;

case:
    CASE INT_LITERAL ARROW statement |
    CASE error ';'
    { yyerror("Syntax Error"); } ;

if_statement:
    IF condition THEN statement elsif_parts ELSE statement ENDIF ';' ;

elsif_parts:
    /* empty */ |
    elsif_parts ELSIF condition THEN statement ;

fold_statement:
    FOLD direction operator list_choice ENDFOLD ';' ;

direction:
    LEFT |
    RIGHT ;

operator:
    ADDOP |
    MULOP ;

list_choice:
    list |
    IDENTIFIER ;

condition:
    or_condition ;

or_condition:
    and_condition |
    or_condition OROP and_condition ;

and_condition:
    not_condition |
    and_condition ANDOP not_condition ;

not_condition:
    relation |
    NOTOP relation |
    '(' condition ')' ;

relation:
    expression RELOP expression ;

expression:
    term |
    expression ADDOP term ;

term:
    factor |
    term MULOP factor |
    term MODOP factor ;

factor:
    exponent |
    factor EXPOP exponent ;

exponent:
    primary |
    NEGOP primary ;

primary:
    INT_LITERAL |
    REAL_LITERAL |
    CHAR_LITERAL |
    IDENTIFIER '(' expression ')' |
    IDENTIFIER |
    '(' expression ')' ;

%%

void yyerror(const char* message)
{
    appendError(SYNTAX, message);
}