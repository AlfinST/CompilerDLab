%{
#include <stdio.h>
#include <stdlib.h>
%}

%token ID NUM FOR LE GE EQ NE OR AND
%right "="
%left OR AND
%left '>' '<' LE GE EQ NE
%left '+' '-'
%left '*' '/'
%right UMINUS
%left '!'

%%
   
//S         : ST {printf("Input accepted\n"); exit(0);}
S       : FOR '(' E ';' E2 ';' E ')' DEF {printf("Input accepted\n"); exit(0);}
           ;
DEF    : '{' BODY '}'
           | E';'
           | S
           |
           ;
BODY  : BODY BODY
           | E ';'       
           | S
           |            
           ;
       
E        : ID '=' E
          | E '+' E
          | E '-' E
          | E '*' E
          | E '/' E
          | E '<' E
          | E '>' E
          | E LE E
          | E GE E
          | E EQ E
          | E NE E
          | E OR E
          | E AND E
          | E '+' '+'
          | E '-' '-'
          | ID 
          | NUM
          ;

   
E2     : E'<'E
         | E'>'E
         | E LE E
         | E GE E
         | E EQ E
         | E NE E
         | E OR E
         | E AND E
         ;   
%%
#include "lex.yy.c"
main() {
    printf("Enter the expression:\n");
    yyparse();
}      
