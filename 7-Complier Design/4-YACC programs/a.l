%{
#include "y.tab.h"
%}

%%
"exit"      exit(1);
[0-9]+      { yylval=atoi(yytext); return NUMBER; }
[a-zA-Z]    { yylval=yytext[0]; return VARIABLE; }
[-+*/=\n]   return *yytext;
[ \t]       ;
%%

int yywrap(void) {
    return 1;
}
