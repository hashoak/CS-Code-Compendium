%{
#include "y.tab.h"
%}

name [A-Z]+
pan [A-Z]{5}[0-9]{4}[A-Z]{1}

%%
^{name}[ ]{pan}$          { yylval=(yytext[0]==yytext[yyleng-1]); return LINE; }
[ \n]                     return *yytext;
.*\n                      printf("INVALID\n");
%%

int yywrap(void) {
    return 1;
}
