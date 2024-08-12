#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int size;
    char *a;
    int top;
};

struct stack* create(int n)
{
    struct stack* s=malloc(sizeof(struct stack));
    s->size=n;
    s->a=(char*)malloc(n*sizeof(char));
    s->top=-1;
    return s;
}

int isEmpty(struct stack *s)
{
    return s->top==-1;
}

int isFull(struct stack *s)
{
    return s->top==s->size-1;
}

void push(struct stack *s, char x)
{
    if(isFull(s))
    {
        printf("Stack overflow.\n");
        return;
    }
    s->top++;
    s->a[s->top]=x;
    return;
}

char pop(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack underflow.\n");
        return '~';
    }
    s->top--;
    return s->a[s->top+1];
}

char peek(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("No elements to peek.\n");
        return '~';
    }
    return s->a[s->top];
}

int size(struct stack *s)
{
    return s->top+1;
}

int check_balanced(char *s)
{
    int l=1,i,b=0;
    struct stack *mem=create(strlen(s));
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='\n') l++,b=1;
        else if(s[i]==')' && peek(mem)=='(') b=0,pop(mem);
        else if(s[i]==']' && peek(mem)=='[') b=0,pop(mem);
        else if(s[i]=='}' && peek(mem)=='{') b=0,pop(mem);
        else if(s[i]=='(' || s[i]=='[' || s[i]=='{') push(mem,s[i]);
        else if(s[i]==')' || s[i]==']' || s[i]=='}') break;
    }
    if(i==strlen(s) && isEmpty(mem))
        printf("The input has balanced parentheses.\n");
    else
        printf("The input is unbalanced in line number %d\n",l-b);
}

int main()
{
    int n;
    printf("Enter the number of lines in the input: ");
    scanf("%d",&n);
    char *input=(char*)malloc(5000*sizeof(char));
    strcpy(input,"");
    char *x=(char*)malloc(300*sizeof(char));
    scanf("%c",x);
    printf("Enter the input:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%[^\n]%*c",x);
        strcat(input,x);
        strcat(input,"\n");    
    }
    check_balanced(input);
    return 0;
}