# CMSC 430 Compiler Theory and Design
# Project 2 Makefile
# Spring 2023

CC = g++
CFLAGS = -g -Wall
OBJS = listing.o parser.tab.o scanner.o compiler.o

compile: $(OBJS)
	$(CC) $(CFLAGS) -o compile $(OBJS)

parser.tab.h parser.tab.c: parser.y
	bison -d parser.y

parser.tab.o: parser.tab.c
	$(CC) $(CFLAGS) -c parser.tab.c

scanner.o: scanner.l parser.tab.h listing.h
	flex scanner.l
	$(CC) $(CFLAGS) -c lex.yy.c -o scanner.o

listing.o: listing.cc listing.h
	$(CC) $(CFLAGS) -c listing.cc

compiler.o: compiler.cc listing.h
	$(CC) $(CFLAGS) -c compiler.cc

clean:
	rm -f *.o lex.yy.c parser.tab.h parser.tab.c compile