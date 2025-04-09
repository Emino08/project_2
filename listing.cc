// CMSC 430 Compiler Theory and Design
// Project 2
// Spring 2023

// This file contains the bodies of the functions that produces the 
// compilation listing

#include <cstdio>
#include <string>

using namespace std;

#include "listing.h"

static int lineNumber;
static string error = "";
static int lexicalErrors = 0;
static int syntaxErrors = 0;
static int semanticErrors = 0;

static void displayErrors();

void firstLine()
{
    lineNumber = 1;
    printf("\n%4d  ", lineNumber);
}

void nextLine()
{
    displayErrors();
    lineNumber++;
    printf("%4d  ", lineNumber);
}

int lastLine()
{
    printf("\r");
    displayErrors();
    printf("     \n");
    return lexicalErrors;
}
    
void appendError(ErrorCategories errorCategory, string message)
{
    string messages[] = { "Lexical Error, Invalid Character ", "Syntax Error, Unexpected ",
        "Semantic Error, ", "Semantic Error, Duplicate ",
        "Semantic Error, Undeclared " };

    error = messages[errorCategory] + message;
    
    switch (errorCategory)
    {
        case LEXICAL:
            lexicalErrors++;
            break;
        case SYNTAX:
            syntaxErrors++;
            break;
        case GENERAL_SEMANTIC:
        case DUPLICATE_IDENTIFIER:
        case UNDECLARED:
            semanticErrors++;
            break;
    }
}

void displayErrors()
{
    if (error != "")
        printf("%s\n", error.c_str());
    error = "";
}