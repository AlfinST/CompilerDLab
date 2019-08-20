# How to Compile and run:
  1. lex program_name.
  > * This produces a lex.yy.c file.
  2. cc lex.yy.c -lfl 
  > * This can be changed to just cc lex.yy.c if you add yywrap(void){} in the program
  3. ./a.out
  > * Runs like any other program.
