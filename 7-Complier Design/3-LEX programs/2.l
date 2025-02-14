%{
#include <stdio.h>
int operatorCount=0;
int identifierCount=0;
int keywordCount=0;
int specialSymbolCount=0;
%}

%%
"short"|"int"|"long"|"float"|"double"|"unsigned"|"signed"|"char"|"void"|"if"|"else"|"else if"|"for"|"while"|"do"|"goto"|"return"|"auto"|"break"|"case"|"const"|"continue"|"default"|"sizeof"|"static"|"struct"|"switch"|"typedef"   { keywordCount++; }
[0-9]+                          { /* Ignore numbers */ }
[a-zA-Z_][a-zA-Z0-9_]*          { identifierCount++; }
"=="|"!="|"<"|">"|"<="|">="|"++"|"--"|"+"|"-"|"*"|"/"|"%"|"="|"&"|"|"|"!"|"&&"|"||"|"<<"|">>"|"+="|"-="|"*="|"/="|"%="|"=="|"!="|"<="|">="|"<<"|">>"|"&="|"|="|"^="|"~"|"->"|"."    { operatorCount++; }
"("|")"|"["|"]"|"{"|"}"|","|";"|":"|"?"   { specialSymbolCount++; }
.|\n                            { /* Ignore all other characters */ }
%%

int main(int argc,char* argv[])
{
    yyin=fopen(argv[1],"r");
    yylex();
    printf("Number of operators: %d\n",operatorCount);
    printf("Number of identifiers: %d\n",identifierCount);
    printf("Number of keywords: %d\n",keywordCount);
    printf("Number of special symbols: %d\n",specialSymbolCount);
    return 0;
}

int yywrap()
{
    return 1;
}
