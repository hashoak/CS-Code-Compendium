%{
#include <stdio.h>
int vowelCount = 0;
int consonantCount = 0;
%}

%%
[aAeEiIoOuU]    { vowelCount++; }
[^aAeEiIoOuU\n] { consonantCount++; }
.|\n            { /* Ignore all other characters and newlines */ }
%%

int main()
{
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    yy_scan_string(input);
    yylex();
    printf("Number of vowels: %d\n", vowelCount);
    printf("Number of consonants: %d\n", consonantCount);
    return 0;
}

int yywrap()
{
    return 1;
}
