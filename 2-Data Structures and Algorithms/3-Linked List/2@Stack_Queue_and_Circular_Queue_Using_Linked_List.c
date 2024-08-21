#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

struct Stack
{
    node *top;
};

typedef struct Stack stack;

struct Queue
{
    node *front;
    node *rear;
};

typedef struct Queue queue;

struct CQueue
{
    node *front;
    node *rear;
};

typedef struct CQueue cqueue;

node* create_node(int x)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->data=x;
    temp->next=NULL;
    return temp;
}

stack* create_stack()
{
    stack* s=(stack*)malloc(sizeof(stack));
    s->top=NULL;
    return s;
}

queue* create_queue()
{
    queue* q=(queue*)malloc(sizeof(queue));
    q->front=q->rear=NULL;
    return q;
}

cqueue* create_cqueue()
{
    cqueue* cq=(cqueue*)malloc(sizeof(cqueue));
    cq->front=cq->rear=NULL;
    return cq;
}

int isEmpty_stack(stack *s)
{
    return s->top==NULL;
}

int isEmpty_queue(queue *q)
{
    return q->front==NULL;
}

int isEmpty_cqueue(cqueue *cq)
{
    return cq->front==NULL && cq->rear==NULL;
}

void push(stack *s,int x)
{
    node *temp=create_node(x);
    if(!temp)
    {
        printf("\nStack Overflow.\n");
        return;
    }
    temp->next=s->top;
    s->top=temp;
    return;
}

void enqueue(queue *q,int x)
{
    node *temp=create_node(x);
    if(!temp)
    {
        printf("\nQueue Overflow.\n");
        return;
    }
    if(q->rear==NULL)
    {
        q->front=q->rear=temp;
        return;
    }
    q->rear->next=temp;
    q->rear=temp;
}

void cenqueue(cqueue *cq,int x)
{
    node *temp=create_node(x);
    if(isEmpty_cqueue(cq))
    {
        cq->front=cq->rear=temp;
        cq->rear->next=cq->front;
    }
    else
    {
        cq->rear->next=temp;
        cq->rear=temp;
        temp->next=cq->front;
    }
    return;
}

void pop(stack *s)
{
    if(isEmpty_stack(s))
    {
        printf("\nStack underflow.\n");
        return;
    }
    node *del=s->top;
    s->top=s->top->next;
    free(del);
    return;
}

void dequeue(queue *q)
{
    if(isEmpty_queue(q))
    {
        printf("Queue underflow.\n");
        return;
    }
    node *del=q->front;
    q->front=q->front->next;
    if(q->front==NULL) q->rear=NULL;
    free(del);
    return;
}

void cdequeue(cqueue *cq)
{
    if(isEmpty_cqueue(cq))
    {
        printf("Queue underflow.\n");
        return;
    }
    node *del=cq->front;
    if(cq->front==cq->rear) cq->front=cq->rear=NULL;
    else
    {
        cq->front=cq->front->next;
        cq->rear->next=cq->front;
    }
    free(del);
    return;
}

int peek_stack(stack *s)
{
    if(isEmpty_stack(s))
    {
        printf("No elements to peek.\n");
        return 0;
    }
    return s->top->data;
}

int peek_queue(queue *q)
{
    if(isEmpty_queue(q))
    {
        printf("No elements to peek.\n");
        return 0;
    }
    return q->front->data;
}

int peek_cqueue(cqueue *cq)
{
    if(isEmpty_cqueue(cq))
    {
        printf("No elements to peek.\n");
        return 0;
    }
    return cq->front->data;
}

void rec_disp(node *n)
{
    if(n==NULL) return;
    printf("%d ",n->data);
    rec_disp(n->next);
    return;
}

void display_stack(stack *s)
{
    if(isEmpty_stack(s)) printf("Stack is empty.");
    else rec_disp(s->top);
    printf("\n");
    return;
}

void display_queue(queue *q)
{
    if(isEmpty_queue(q))
    {
        printf("Queue is empty.");
    }
    for(node *t=q->front;t!=NULL;t=t->next)
    {
        printf("%d ",t->data);
    }
    printf("\n");
    return;
}

void display_cqueue(cqueue *cq)
{
    if(isEmpty_cqueue(cq))
    {
        printf("Queue is empty.");
        return;
    }
    node *t=cq->front;
    do
    {
        printf("%d ",t->data);
        t=t->next;
    }while(t!=cq->front);
    printf("\n");
    return;
}

int main()
{
    printf("Stack:\n");
    stack *s=create_stack();
    push(s,10);
    display_stack(s);
    push(s,20);
    display_stack(s);
    push(s,30);
    display_stack(s);
    pop(s);
    display_stack(s);
    pop(s);
    display_stack(s);
    pop(s);
    display_stack(s);
    
    printf("\nQueue:\n");
    queue *q=create_queue();
    enqueue(q,10);
    display_queue(q);
    enqueue(q,20);
    display_queue(q);
    enqueue(q,30);
    display_queue(q);
    dequeue(q);
    display_queue(q);
    dequeue(q);
    display_queue(q);
    dequeue(q);
    display_queue(q);
    
    printf("\nCircular Queue:\n");
    cqueue *cq=create_cqueue();
    cenqueue(cq,10);
    display_cqueue(cq);
    cenqueue(cq,20);
    display_cqueue(cq);
    cenqueue(cq,30);
    display_cqueue(cq);
    cdequeue(cq);
    display_cqueue(cq);
    cdequeue(cq);
    display_cqueue(cq);
    cdequeue(cq);
    display_cqueue(cq);
    return 0;
}