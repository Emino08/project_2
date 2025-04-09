/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INT_LITERAL = 259,             /* INT_LITERAL  */
    REAL_LITERAL = 260,            /* REAL_LITERAL  */
    CHAR_LITERAL = 261,            /* CHAR_LITERAL  */
    ADDOP = 262,                   /* ADDOP  */
    MULOP = 263,                   /* MULOP  */
    RELOP = 264,                   /* RELOP  */
    ANDOP = 265,                   /* ANDOP  */
    OROP = 266,                    /* OROP  */
    NOTOP = 267,                   /* NOTOP  */
    EXPOP = 268,                   /* EXPOP  */
    MODOP = 269,                   /* MODOP  */
    NEGOP = 270,                   /* NEGOP  */
    BEGIN_ = 271,                  /* BEGIN_  */
    BOOLEAN = 272,                 /* BOOLEAN  */
    CASE = 273,                    /* CASE  */
    CHARACTER = 274,               /* CHARACTER  */
    ELSE = 275,                    /* ELSE  */
    ELSIF = 276,                   /* ELSIF  */
    END = 277,                     /* END  */
    ENDFILE = 278,                 /* ENDFILE  */
    ENDIF = 279,                   /* ENDIF  */
    ENDSWITCH = 280,               /* ENDSWITCH  */
    FUNCTION = 281,                /* FUNCTION  */
    IF = 282,                      /* IF  */
    INTEGER = 283,                 /* INTEGER  */
    IS = 284,                      /* IS  */
    LIST = 285,                    /* LIST  */
    MAIN = 286,                    /* MAIN  */
    OF = 287,                      /* OF  */
    OTHERS = 288,                  /* OTHERS  */
    REAL = 289,                    /* REAL  */
    RETURNS = 290,                 /* RETURNS  */
    SWITCH = 291,                  /* SWITCH  */
    THEN = 292,                    /* THEN  */
    WHEN = 293,                    /* WHEN  */
    ARROW = 294,                   /* ARROW  */
    FOLD = 295,                    /* FOLD  */
    LEFT = 296,                    /* LEFT  */
    RIGHT = 297,                   /* RIGHT  */
    ENDFOLD = 298                  /* ENDFOLD  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "parser.y"

	char* iden;
	char* text;

#line 112 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
