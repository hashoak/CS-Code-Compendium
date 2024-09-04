#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

struct stack
{
    node *top;
};

struct stack* create()
{
    struct stack* s=malloc(sizeof(struct stack));
    s->top=NULL;
    return s;
}

int isEmpty(struct stack *s)
{
    return s->top==NULL;
}

void push(struct stack *s,int x)
{
    node *temp=(node*)malloc(sizeof(node));
    if(!temp)
    {
        printf("\nStack Overflow.\n");
        return;
    }
    temp->data=x;
    temp->next=s->top;
    s->top=temp;
    return;
}

void pop(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("\nStack underflow.\n");
        return;
    }
    node *del=s->top;
    s->top=s->top->next;
    free(del);
    return;
}

int peek(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("No elements to peek.\n");
        return 0;
    }
    return s->top->data;
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