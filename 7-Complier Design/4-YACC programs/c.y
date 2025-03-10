%{
#include <stdio.h>
#include <string.h>

#define YYSTYPE char*
extern char* yylval;
extern int yylex();
void yyerror(const char* s);
%}

%token NUMBER

%left '+' '-'
%left '*' '/'

%%
input   : expr '\n' { printf("O/P: %s\n",$1); return 0;}
        ;

expr: expr '+' expr { $$=strcat(strcat($1,$3),"+ "); }
    | expr '-' expr { $$=strcat(strcat($1,$3),"- "); }
    | expr '*' expr { $$=strcat(strcat($1,$3),"* "); }
    | expr '/' expr { $$=strcat(strcat($1,$3),"/ "); }
    | NUMBER { char num[16]; sprintf(num,"%d ",$1); $$=strdup(num); }
    ;

%%

int main() {
    printf("I/P: ");
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    printf("Error: %s\n",s);
    exit(1);
}

// I/P: 5 - 3 + 2 * 8 / 6
// O/P: 5 3 - 2 8 * 6 / +
// I/P: 2 + 3 - 1 / 5 * 18
// O/P: 2 3 + 1 5 / 18 * -