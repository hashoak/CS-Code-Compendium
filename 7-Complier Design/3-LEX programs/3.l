%{
#include <stdio.h>
int wordCount=0;
%}

vowel [aAeEiIoOuU]
alpha [a-zA-Z]

%%
{alpha}*{vowel}{alpha}*{vowel}{alpha}* {
        printf("%s\n",yytext);
        wordCount++;
    }
.|\n        { /* Ignore all other characters and newlines */ }
%%

int main(int argc,char* argv[])
{
    // yyin=fopen(argv[1],"r");
    char arr[100];
    fgets(arr,100,stdin);
    yy_scan_string(arr);
    yylex();
    printf("Number of words with at least two vowels: %d\n",wordCount);
    return 0;
}

int yywrap()
{
    return 1;
}
