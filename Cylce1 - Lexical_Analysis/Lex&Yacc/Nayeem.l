str "aba"
%{ 
    int count; 
%} 
%% 
    /* match identifier */ 
.*({str}({str})*)+       {count++;printf("a");} 
.*  {printf(yytext);}
%% 
int main(void) { 
    yylex(); 
    printf("number of substring = %d\n", count); 
    return 0; 
} 