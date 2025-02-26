%{
#include<stdio.h>
%}

%%
"<"[^>]*> {printf("%s\n", yytext); }
.|\n        { /* Ignore all other characters and newlines */ }
%%

int main(int argc,char* argv[])
{
    yyin=fopen(argv[1],"r");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
