%{
#include "y.tab.h"
#include<string.h>
%}

%%
[0-9]+      { yylval=atoi(yytext); return NUMBER; }
[-+*/\n]    return *yytext;
[ \t]       ;
.           yyerror("invalid character");
%%

int yywrap(void) {
    return 1;
}
