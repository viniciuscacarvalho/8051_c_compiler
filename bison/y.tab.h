/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Skeleton interface for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 23 "bison_test.y"

    #define _GNU_SOURCE
    #include <stdio.h>
    #include "node.h"

    typedef struct driver {
        const char *file;
        FILE *fd;
        node_t *root;
        void *scanner;
    } driver_t;

    #define YYLTYPE loc_t

#line 59 "y.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    TOK_EOF = 0,                   /* "end of input"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* "identifier"  */
    STRING = 259,                  /* "string literal"  */
    INTEGER = 260,                 /* "integer literal"  */
    FLOAT = 261,                   /* "float literal"  */
    TOK_FOO = 262,                 /* "foo"  */
    TOK_BAR = 263                  /* "bar"  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "bison_test.y"

    const char *string;
    node_t *node; 

#line 89 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (driver_t *driver, void *scanner);
/* "%code provides" blocks.  */
#line 92 "bison_test.y"

    /* entry point for parsing files */
    node_t *example_parse(const char *file);

    /* shared error handler */
    void yyerror(loc_t *loc, driver_t *driver, void*, const char *msg);

    /* provided by lexer to circumvent lexer-header problems */
    extern void example_lexer_begin(driver_t *driver);
    extern void example_lexer_end(driver_t *driver);

    /* NOTE: lexer protoype is in the parser-header to prevent
     *       conflicting types.
     */
    #define YY_DECL int yylex \
               (YYSTYPE* yylval_param, loc_t* yylloc_param , void *yyscanner)
    extern YY_DECL;


#line 135 "y.tab.h"

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
