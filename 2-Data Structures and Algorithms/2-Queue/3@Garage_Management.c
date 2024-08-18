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

stack* create_stack()
{
    stack* s=(stack*)malloc(sizeof(stack));
    s->top=NULL;
    return s;
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
    rec_disp(n->next);
    printf("%d ",n->data);
    return;
}

void display_stack(stack *s)
{
    if(isEmpty_stack(s)) printf("Stack is empty.\n");
    else rec_disp(s->top);
    return;
}

void display_queue(queue *q)
{
    if(isEmpty_queue(q))
    {
        printf("Queue is empty.\n");
    }
    for(node *t=q->front;t!=NULL;t=t->next)
    {
        printf("%d ",t->data);
    }
    return;
}

void display_cqueue(cqueue *cq)
{
    if(isEmpty_cqueue(cq))
    {
        printf("Queue is empty.\n");
    }
    node *t=cq->front;
    do
    {
        printf("%d ",t->data);
        t=t->next;
    }while(t!=cq->front);
    return;
}

void on_road(queue *road,int id)
{
    enqueue(road,id);
    return;
}

void enter_garage(queue *road,stack *gar,int id)
{
    if(id!=road->front->data)
    {
        printf("Truck %d cannot be moved.\n",id);
        return;
    }
    else push(gar,peek_queue(road));
    dequeue(road);
    return;
}

void exit_garage(stack *gar,int id)
{
    if(id!=gar->top->data)
    {
        printf("Truck %d cannot be moved.\n",id);
        return;
    }
    int ser=0;
    printf("Number of services done for truck %d: ",id);
    scanf("%d",&ser);
    printf("Service charges for the truck %d is $%d\n",id,ser*100);
    pop(gar);
    return;
}

void show_trucks(queue *road,stack *gar,char x[])
{
    if(!strcmp(x,"Garage"))
    {
        printf("Trucks in garage: ");
        display_stack(gar);
    }
    else if(!strcmp(x,"Road"))
    {
        printf("Trucks on road: ");
        display_queue(road);
    }
    else printf("Invalid Input!");
    printf("\n");
    return;
}

void enter_garage_2(cqueue *gar,int id)
{
    cenqueue(gar,id);
    return;
}

void exit_garage_2(cqueue *gar,int id)
{
    if(id!=gar->front->data)
    {
        printf("Truck %d cannot be moved.\n",id);
        return;
    }
    int ser=0;
    printf("Number of services done for truck %d: ",id);
    scanf("%d",&ser);
    printf("Service charges for the truck %d is $%d\n",id,ser*100);
    cdequeue(gar);
    return;
}

void show_trucks_2(cqueue *gar)
{
    printf("Trucks in garage: ");
    display_cqueue(gar);
    printf("\n");
    return;
}

int main()
{
    printf("Garage 1:\n");
    queue *road=create_queue();
    stack *garage=create_stack();
    int type=0,truck_id;
    printf("Enter the type command:\n1. On_road\n2. Enter_garage\n3. Exit_garage\n4. Show_trucks\n5. End\n");
    while(type!=5)
    {
        scanf("%d",&type);
        if(type>0 && type<4)
        {
            printf("Enter the Truck ID: ");
            scanf("%d",&truck_id);
        }
        if(type==1) on_road(road,truck_id);
        else if(type==2) enter_garage(road,garage,truck_id);
        else if(type==3) exit_garage(garage,truck_id);
        else if(type==4)
        {
            char x[10];
            printf("Show Garage or Road: ");
            scanf("%s",x);
            show_trucks(road,garage,x);
        }
        else if(type!=5) printf("Wrong Input!\n");
    }
    printf("\nGarage 2:\n");
    cqueue *garage_2=create_cqueue();
    type=0,truck_id;
    printf("Enter the type command:\n1. Enter garage\n2. Exit garage\n3. Show trucks\n4. End\n");
    while(type!=4)
    {
        scanf("%d",&type);
        if(type>0 && type<3)
        {
            printf("Enter the Truck ID: ");
            scanf("%d",&truck_id);
        }
        if(type==1) enter_garage_2(garage_2,truck_id);
        else if(type==2) exit_garage_2(garage_2,truck_id);
        else if(type==3) show_trucks_2(garage_2);
        else if(type!=4) printf("Wrong Input!\n");
    }

    return 0;
}