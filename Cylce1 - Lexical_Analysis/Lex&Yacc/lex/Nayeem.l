str "aba"
%{ 
    int count; 
%} 
%% 
    /* match identifier */ 
({str})       {count++;printf("a");} 
%% 
int main(void) { 
    yylex(); 
    printf("number of substring = %d\n", count); 
    return 0; 
} 