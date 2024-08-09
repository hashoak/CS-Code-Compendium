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

int isEmpty(struct stack *s)
{
    return s->top==-1;
}

int isFull(struct stack *s)
{
    return s->top==s->size-1;
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

char* peek(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("No elements to peek.\n");
        return "-1";
    }
    return s->a[s->top];
}

int size(struct stack *s)
{
    return s->top+1;
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

void check_sub(struct stack *s,char *check)
{
    if(isEmpty(s))
    {
        printf("Stack is empty.\n");
        return;
    }
    int c=0;
    for(int i=0;i<=s->top;i++)
    {
        if(strcmp(s->a[i],check)==0)
        {
            c=1;
            break;
        }
    }
    if(c) printf("%s has submitted the assignment.\n");
    else printf("%s has not submitted the assignment.\n");
    return;
}

void check_duplicate(struct stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack is empty.\n");
        return;
    }
    int ch[size(s)],c=1;
    for(int i=0;i<size(s);i++)
    {
        ch[i]=1;
    }
    for(int i=0;i<=s->top;i++)
    {
        if(ch[i])
        {
            for(int j=i+1;j<=s->top;j++)
            {
                if(strcmp(s->a[i],s->a[j])==0)
                {
                    ch[i]=0;
                    ch[j]=0;
                }
            }
            if(ch[i]==0)
            {
                c=0;
                printf("%s has made multiple submissions.\n",s->a[i]);
            }
            ch[i]=0;
        }
    }
    if(c) printf("There are no duplicate submissions.\n");
    return;
}

int main()
{
    struct stack* sub=create(100);
    int n;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    printf("Enter the register numbers of %d students: \n",n);
    for(int i=0;i<n;i++)
    {
        char x[100];
        scanf("%s",x);
        push(sub,x);
    }

    printf("\nRegister number of the last submitted record: %s\n\n",peek(sub));

    check_duplicate(sub); // Innovativeness: Checks if any student has done multiple submissions.

    char check[100];
    printf("\nEnter the register number to be checked: ");
    scanf("%s",check);
    check_sub(sub,check);
    
    while(size(sub)>10)
    {
        pop(sub);
    }
    printf("\nFirst 10 students to submit the assignment:\n");
    display(sub);
    return 0;
}