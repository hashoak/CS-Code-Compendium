%{
#include <stdio.h>

extern int yylex();
void yyerror(const char* s);
extern FILE *yyin;
char ch;
%}

%token LINE

%%
S   :
    | S LINE '\n' {
        if($2) printf("VALID\n");
        else printf("INVALID\n");
    }
    ;

%%

int main(int argc,char* argv[]) {
    yyin=fopen(argv[1],"r");
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    printf("INVALID\n");
    yyparse();
}
