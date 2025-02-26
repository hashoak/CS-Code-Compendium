%{
#include<stdio.h>
int wordCount=0;
%}

%%
^[cC][a-zA-Z]*[tT]$ {
        printf("%s\n",yytext);
        wordCount++;
    }
.|\n        { /* Ignore all other characters and newlines */ }
%%

int main(int argc,char* argv[])
{
    yyin=fopen(argv[1],"r");
    yylex();
    printf("Number of words with \"c\" or \"C\" as start and \"t\" or \"T\" as end: %d\n",wordCount);
    return 0;
}

int yywrap()
{
    return 1;
}
