%union {
    char* string;
}

%{
    #define _GNU_SOURCE
    #include <stdio.h>
    int yylex();
    void yyerror(const char* msg);
%}



%token          TOK_EOF     0       "end of input"
%token <string> ID                  "identifier"
%token <string> LETTER              "string literal"
%token <string> NUMBER             "integer literal"
%token <string> FLOAT               "float literal"

%% /*program */
program: ID NUMBER ID {printf("IDENT NUMBER IDENT \n");}
%%
void yyerror(const char *msg)
{
    printf("%s error", msg);
}
int main(int argc, char **argv)
{
    yyparse();
}