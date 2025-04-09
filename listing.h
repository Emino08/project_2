// CMSC 430 Compiler Theory and Design
// Project 2
// Spring 2023

// This file contains the function prototypes for the functions that produce
// the compilation listing

#ifndef LISTING_H
#define LISTING_H

#include <string>

using namespace std;

enum ErrorCategories {LEXICAL, SYNTAX, GENERAL_SEMANTIC, DUPLICATE_IDENTIFIER,
    UNDECLARED};

void firstLine();
void nextLine();
int lastLine();
void appendError(ErrorCategories errorCategory, string message);

#endif