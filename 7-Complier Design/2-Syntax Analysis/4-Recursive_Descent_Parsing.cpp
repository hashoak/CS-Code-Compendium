#include <stdio.h>
#include <stdlib.h>

// E -> TE'
// E' -> +TE' | ε
// T -> FT'
// T' -> *FT' | ε
// F -> (E) | id

char l;

void E();

void match(char c)
{
    if(l==c) l=getchar();
    else
    {
        printf("Invalid Input\n");
        exit(0);
    }
}

void F()
{
    if(l=='(')
    {
        match('(');
        E();
        match(')');
    }
    else
    {
        match('i');
        match('d');
    }
}

void T_()
{
    if(l=='*')
    {
        match('*');
        F();
        T_();
    }
}

void T()
{
    F();
    T_();
}

void E_()
{
    if(l=='+')
    {
        match('+');
        T();
        E_();
    }
}

void E()
{
    T();
    E_();
}

int main()
{
    char input[10];
    printf("Enter String with $ at the end\n");
    l = getchar();
    E();
    if(l=='$')
    {
        printf("Parsing Successful\n");
    }
    else
    {
        printf("Invalid Input\n");
    }
    return 0;
}