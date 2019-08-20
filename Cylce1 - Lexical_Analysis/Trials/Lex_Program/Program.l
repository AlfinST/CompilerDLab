%{

    #include <stdio.h>
    Kcount=0;
    Icount=0;
%}

%%
    if|else|while|int|switch|for|char|float|void|struct|    {Kcount++;}
    [a-z]([a-z]|[0-9])*    {Icount++;}
    .*    {printf("invalid");}
%%

main()
{
    yylex();
    return 0;
}
