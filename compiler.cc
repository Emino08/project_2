// CMSC 430 Compiler Theory and Design
// Project 2
// Spring 2023

// This file contains the main driver for the compiler.

#include <iostream>
#include <string>

using namespace std;

#include "listing.h"

extern int yyparse();

int main()
{
    firstLine();
    
    if (yyparse() == 0)
        cout << "Compiled Successfully" << endl;
    
    int lexicalErrors = lastLine();
    cout << "Lexical Errors " << lexicalErrors << endl;
    cout << "Syntax Errors " << 0 << endl;
    cout << "Semantic Errors " << 0 << endl;
    
    return 0;
}