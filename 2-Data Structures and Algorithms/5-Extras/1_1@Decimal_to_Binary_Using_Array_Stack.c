#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int size;
    int *a;
    int top;
};

struct stack* create(int n)
{
    struct stack* s=malloc(sizeof(struct stack));
    s->size=n;
    s->a=(int*)malloc(n*sizeof(int));
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

void push(struct stack *s,int x)
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

int pop(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack underflow.\n");
        return -1;
    }
    s->top--;
    return s->a[s->top+1];
}

int peek(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("No elements to peek.\n");
        return -1;
    }
    return s->a[s->top];
}

void decimalToBinary(int dec)
{
    struct stack *S=create(100);
    while(dec!=0)
    {
        push(S,dec%2);
        dec/=2;
    }
    while(!isEmpty(S))
    {
        printf("%d",peek(S));
        pop(S);
    }
    return;
}

int main()
{
    int dec;
    printf("Enter the Decimal value: ");
    scanf("%d",&dec);
    decimalToBinary(dec);
    return 0;
}