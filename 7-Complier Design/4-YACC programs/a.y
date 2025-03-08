%{
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VARIABLES 26

int variables[MAX_VARIABLES];

void assign_variable(char var,int value) {
    variables[var-'A']=value;
}

int get_variable(char var) {
    return variables[var-'A'];
}

bool is_variable_assigned(char var) {
    return variables[var-'A']!=0;
}

void yyerror(const char* s);

int yylex();
%}

%token NUMBER
%token VARIABLE

%left '+' '-'
%left '*' '/'

%%
calc: /* empty */
    | calc statement '\n'
    ;

statement: /* empty */
    | assignment
    | expr              { printf("Result: %d\n",$1); }
    ;

assignment:
    VARIABLE '=' expr   { assign_variable($1,$3); }
    ;

expr:
    NUMBER              { $$=$1; }
    | VARIABLE          { if(is_variable_assigned($1)) $$=get_variable($1); else yyerror("Variable not assigned."); }
    | expr '+' expr     { $$=$1+$3; }
    | expr '-' expr     { $$=$1-$3; }
    | '-' expr          { $$=-$2; }
    | expr '*' expr     { $$=$1*$3; }
    | expr '/' expr     { 
                            if($3==0) yyerror("Division by zero.");
                            else $$=$1/$3;
                        }
    ;

%%

int main() {
    for(int i=0;i<MAX_VARIABLES;i++) {
        variables[i]=0;
    }
    yyparse();
    return 0;
}

void yyerror(const char* s) {
    fprintf(stderr,"Error: %s\n",s);
    yyparse();
}

// Input:
// A=120
// A + 220
// B=-10
// B + A
// A / 0
// C=2 * A-B
// C
// exit