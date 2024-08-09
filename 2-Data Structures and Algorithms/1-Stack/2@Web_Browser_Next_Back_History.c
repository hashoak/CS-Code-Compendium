#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int size;
    char **a;
    int top;
};

struct stack* create(int n)
{
    struct stack* s=malloc(sizeof(struct stack));
    s->size=n;
    s->a=(char**)malloc(n*sizeof(char*));
    for(int i=0;i<n;i++)
    {
        s->a[i]=(char*)malloc(100*sizeof(char));
    }
    s->top=-1;
    return s;
}

void combine(struct stack *s1,struct stack *s2)
{
    free(s1->a);    // Deletes both the arrays
    free(s2->a);    // from the stacks.
    s1->size+=s2->size;     // Combines the sizes of
    s2->size=s1->size;      // both the stacks.
    s1->a=(char**)malloc((s1->size)*sizeof(char*));     // Creates a common array
    for(int i=0;i<(s1->size);i++)                       // for both the stacks.
    {
        s1->a[i]=(char*)malloc(100*sizeof(char));
    }
    s2->a=s1->a;
    s1->top=-1;             // First half of the array is used by backward stack.
    s2->top=(s2->size)/2;   // Second half of the array is used by forward stack.
    return;
}

int isEmpty(struct stack *s)
{
    return s->top==-1;
}

int isEmpty_mid(struct stack *s)    // '_mid' functions are for the stack that
{                                   // shares the second half of the array.
    return s->top==(s->size)/2;
}

int isFull(struct stack *s)
{
    return s->top==(s->size)/2-1;
}

int isFull_mid(struct stack *s)
{
    return s->top==(s->size)-1;
}

void push(struct stack *s, char *x)
{
    if(isFull(s))
    {
        printf("Stack overflow.\n");
        return;
    }
    s->top++;
    strcpy(s->a[s->top],x);
    return;
}

void push_mid(struct stack *s, char *x)
{
    if(isFull_mid(s))
    {
        printf("Stack overflow.\n");
        return;
    }
    s->top++;
    strcpy(s->a[s->top],x);
    return;
}

char* pop(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack underflow.\n");
        return "-1";
    }
    s->top--;
    return s->a[s->top+1];
}

char* pop_mid(struct stack *s)
{
    if(isEmpty_mid(s))
    {
        printf("Stack underflow.\n");
        return "-1";
    }
    s->top--;
    return s->a[s->top+1];
}

char* peek(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("No elements to peek.\n");
        return "-1";
    }
    return s->a[s->top];
}

char* peek_mid(struct stack *s)
{
    if(isEmpty_mid(s))
    {
        printf("No elements to peek.\n");
        return "-1";
    }
    return s->a[s->top];
}

void display(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack is empty.\n");
        return;
    }
    for(int i=s->top;i>=0;i--)
    {
        printf("%s\n",s->a[i]);
    }
    return;
}

void display_mid(struct stack *s)
{
    if(isEmpty_mid(s))
    {
        printf("Stack is empty.\n");
        return;
    }
    for(int i=s->top;i>(s->size)/2;i--)
    {
        printf("%s\n",s->a[i]);
    }
    return;
}

int main()
{
    struct stack *backward=create(100);
    struct stack *forward=create(100);
    combine(backward,forward);  // To implement both the stacks using single array.
    struct stack *history=create(100);
    char *func=(char*)calloc(100,sizeof(char));
    char *present=(char*)calloc(100,sizeof(char));
    char *num=(char*)calloc(100,sizeof(char));
    int pre=1;
    printf("Enter the following keywords for respective operations:\n");
    printf("To go to the next page - \"next\"\n");
    printf("To go to the previous page - \"back\"\n");
    printf("To display all the pages - \"display\"\n");
    printf("To display history - \"history\"\n");   // Innovativeness: Stores and returns history of the websites visited in order.
    printf("To exit the browser - \"exit\"\n");
    itoa(pre,num,10);
    strcpy(present,"Website ");
    strcat(present,num);
    push(history,present);
    do
    {
        printf("\nKeyword: ");
        scanf("%s",func);
        if(strcmp(func,"next")==0)
        {
            push(backward,present);
            if(isEmpty_mid(forward))
            {
                pre++;
                itoa(pre,num,10);
                strcpy(present,"Website ");
                strcat(present,num);
            }
            else
            {
                present=pop_mid(forward);
            }
            push(history,present);
        }
        else if(strcmp(func,"back")==0)
        {
            if(isEmpty(backward))
            {
                printf("You have reached the first page.\n");
            }
            else
            {
                push_mid(forward,present);
                present=pop(backward);
                push(history,present);
            }
        }
        else if(strcmp(func,"display")==0)
        {
            printf("Current website: %s\n",present);
            printf("Previous websites:\n");
            display(backward);
            printf("Next websites:\n");
            display_mid(forward);
        }
        else if(strcmp(func,"history")==0)
        {
            printf("History:\n");
            display(history);
        }
        else if(strcmp(func,"exit")!=0)
        {
            printf("Invalid operation!\n");
        }
    } while(strcmp(func,"exit")!=0);
    printf("Exited!\n");
}