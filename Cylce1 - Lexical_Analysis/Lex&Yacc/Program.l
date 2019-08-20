letter [A-Za-z]
digit [0-9]

%{
    #include <stdio.h>
    int Kcount;
    int Icount;
%}

%%
auto|double|if|static|break|else|int|struct|case|enum|long|switch|char|extern|near|typedef|const|float|continue|register|union|unsigned|void|while|default|do|goto|signed|while|signed  {++Kcount;printf("C keyWord(%d) :\t %s\n",Kcount,yytext);}

\"(\\.|[^"\\])*\" {printf("String:\t%s\n",yytext);fprintf(yyout,yytext);}
\'[a-zA-Z0-9.]\' {printf("Character:\t%s\n",yytext);fprintf(yyout,yytext);}

{letter}({letter}|{digit})*  {++Icount;printf("Identifier (%d) :\t%s\n",Icount,yytext);}
[.*] {fprintf(yyout,yytext);} 
%%
void main()
{
    yyin = fopen("input.c","r");
    yyout = fopen("output.c","w");
    yylex();
    fclose(yyin);
    return 0;

}