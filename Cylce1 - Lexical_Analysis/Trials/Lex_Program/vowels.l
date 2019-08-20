vowel [aeiouAEIOU]

%{ 
    #include<stdio.h> 
    #include<string.h> 
    int vow_count=0; 
    int const_count =0; 

%} 
  
%% 
{vowel} {vow_count++;}
[a-zA-Z] {const_count++;}
"\n" {printf("Number of vowels are:  %d\n", vow_count);
      printf("Number of consonants are:  %d\n", const_count); 
      vow_count =0;
      const_count=0;
      }
%% 
   
 int main() 
{ 
    printf("Enter the string of vowels and consonents:"); 
    yylex(); 
    return 0; 
}  