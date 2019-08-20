str "abb"
%{ 
    int count; 
%} 
%% 
    /* match identifier */ 
.{str}({str})* | {str}({str})*       count++; 
%% 
int main(void) { 
    yylex(); 
    printf("number of substring = %d\n", count); 
    return 0; 
} 