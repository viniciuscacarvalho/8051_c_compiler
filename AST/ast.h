#ifndef __AST__
#define __AST__

#include "../bison/bison_test.tab.h"

typedef struct ast_s ast_t;

struct ast_s
{
    yytoken_kind_t token_kind;// bison.tab.h
    ast_t* siblings; //haha slibings
};

unsigned char match (yytoken_kind_t token);

ast_t*  if_node();

#endif