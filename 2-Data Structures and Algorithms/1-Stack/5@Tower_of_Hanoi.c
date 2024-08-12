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

int size(struct stack *s)
{
    return s->top+1;
}

void display_movement(char *from,char *to,int disk)
{
    printf("Move disk %d from %s to %s\n",disk,from,to);
}

void move_disk(struct stack *from,struct stack *to)
{
    push(to,pop(from));
    return;
}

void toh_non_recursive(int n,struct stack *s,char* s_name,
struct stack *h,char* h_name,struct stack *d,char *d_name)
{
    if(n%2==0)
    {
        struct stack *t=h;
        h=d;
        d=t;
        char *t_name=h_name;
        h_name=d_name;
        d_name=t_name;
    }
    for(int i=1;!isEmpty(s) || (n%2 && !isEmpty(h)) || (n%2==0 && !isEmpty(d));i++)
    {
        if(i%3==1)
        {
            if(isEmpty(d) || (!isEmpty(s) && peek(d)>peek(s)))
            {
                display_movement(s_name,d_name,peek(s));
                move_disk(s,d);
            }
            else
            {
                display_movement(d_name,s_name,peek(d));
                move_disk(d,s);
            }
        }
        else if(i%3==2)
        {
            if(isEmpty(h) || (!isEmpty(s) && peek(h)>peek(s)))
            {
                display_movement(s_name,h_name,peek(s));
                move_disk(s,h);
            }
            else
            {
                display_movement(h_name,s_name,peek(h));
                move_disk(h,s);
            }
        }
        else if(i%3==0)
        {
            if(isEmpty(d) || (!isEmpty(h) && peek(d)>peek(h)))
            {
                display_movement(h_name,d_name,peek(h));
                move_disk(h,d);
            }
            else
            {
                display_movement(d_name,h_name,peek(d));
                move_disk(d,h);
            }
        }
    }
    return;
}

void toh_recursive(int n,struct stack *s,char* s_name,
struct stack *h,char* h_name,struct stack *d,char *d_name)
{
    if(n==0) return;
    toh_recursive(n-1,s,s_name,d,d_name,h,h_name);
    display_movement(s_name,d_name,peek(s));
    move_disk(s,d);
    toh_recursive(n-1,h,h_name,s,s_name,d,d_name);
    return;
}

void display_stacks(int n,struct stack *s,char* s_name,
struct stack *h,char* h_name,struct stack *d,char *d_name)  // Prints the stacks.
{
    if(n%2==0)
    {
        struct stack *t=h;
        h=d;
        d=t;
        char *t_name=h_name;
        h_name=d_name;
        d_name=t_name;
    }
    printf("\n");
    if(size(s)>size(h)) n=size(s);
    else n=size(h);
    if(size(d)>n) n=size(d);
    for(int i=n;i>0;i--)
    {
        if(i<=size(s)) printf("%d ",s->a[s->top-(size(s)-i)]);
        else printf("  ");
        if(i<=size(h)) printf("%d ",h->a[h->top-(size(h)-i)]);
        else printf("  ");
        if(i<=size(d)) printf("%d \n",d->a[d->top-(size(d)-i)]);
        else printf("  \n");
    }
    printf("%s %s %s\n",s_name,h_name,d_name);
}

void toh_movement(int n,struct stack *s,char* s_name,
struct stack *h,char* h_name,struct stack *d,char *d_name)
{
    if(n%2==0)
    {
        struct stack *t=h;
        h=d;
        d=t;
        char *t_name=h_name;
        h_name=d_name;
        d_name=t_name;
    }
    for(int i=1;!isEmpty(s) || (n%2 && !isEmpty(h)) || (n%2==0 && !isEmpty(d));i++)
    {
        display_stacks(n,s,s_name,h,h_name,d,d_name);
        if(i%3==1)
        {
            if(isEmpty(d) || (!isEmpty(s) && peek(d)>peek(s))) move_disk(s,d);
            else move_disk(d,s);
        }
        else if(i%3==2)
        {
            if(isEmpty(h) || (!isEmpty(s) && peek(h)>peek(s))) move_disk(s,h);
            else move_disk(h,s);
        }
        else if(i%3==0)
        {
            if(isEmpty(d) || (!isEmpty(h) && peek(d)>peek(h))) move_disk(h,d);
            else move_disk(d,h);
        }
    }
    display_stacks(n,s,s_name,h,h_name,d,d_name);
    return;
}

int main()
{
    int n;
    printf("Enter the total number of rings: ");
    scanf("%d",&n);
    struct stack *s=create(n);
    struct stack *h=create(n);
    struct stack *d=create(n);
    char *s_name=(char*)malloc(100*sizeof(char));
    char *h_name=(char*)malloc(100*sizeof(char));
    char *d_name=(char*)malloc(100*sizeof(char));
    printf("Enter the name of the source pole: ");
    scanf("%s",s_name);
    printf("Enter the name of the helper pole: ");
    scanf("%s",h_name);
    printf("Enter the name of the destination pole: ");
    scanf("%s",d_name);

    printf("\nRecursive method:\n");
    printf("Flow of execution:\n");
    for(int i=n;i>0;i--) push(s,i);
    toh_recursive(n,s,s_name,h,h_name,d,d_name);
    printf("Destination pole after transfering: ");
    for(int i=n;i>0;i--) printf("%d ",pop(d));
    printf("\n");

    printf("\nNon-Recursive method:\n");
    printf("Flow of execution:\n");
    for(int i=n;i>0;i--) push(s,i);
    toh_non_recursive(n,s,s_name,h,h_name,d,d_name);
    printf("Destination pole after transfering: ");
    for(int i=n;i>0;i--) printf("%d ",pop(d));
    printf("\n");

    printf("\nPoles during the movement: ");
    for(int i=n;i>0;i--) push(s,i);
    toh_movement(n,s,s_name,h,h_name,d,d_name);    // Prints the poles after each movement.
    return 0;
}