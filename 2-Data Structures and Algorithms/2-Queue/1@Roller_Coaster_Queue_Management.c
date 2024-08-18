#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Queue
{
    int size;
    int *a;
    int front,rear;
};

typedef struct Queue queue;

queue* create(int n)
{
    queue* q=malloc(sizeof(queue));
    q->size=n;
    q->a=(int*)malloc(sizeof(int));
    q->front=0;
    q->rear=-1;
    return q;
}

int isEmpty(queue *q)
{
    return (q->rear==-1) || (q->front==q->rear+1);
}

int isFull(queue *q)
{
    return q->rear==q->size-1;
}

void enqueue(queue *q,int x)
{
    if(isFull(q))
    {
        printf("queue overflow.\n");
        return;
    }
    q->rear=(q->rear+1)%q->size;
    q->a[q->rear]=x;
    return;
}

void enqueue_vip(queue *q,int x)
{
    if(isFull(q))
    {
        printf("queue overflow.\n");
        return;
    }
    q->front=(q->front+q->size-1)%q->size;
    q->a[q->front]=x;
    return;
}

int dequeue(queue *q)
{
    if(isEmpty(q))
    {
        printf("queue underflow.\n");
        return -1;
    }
    q->front=(q->front+1)%q->size;
    return q->a[q->front-1];
}

int peek(queue *q)
{
    if(isEmpty(q))
    {
        printf("No elements to peek.\n");
        return -1;
    }
    return q->a[q->front];
}

int size(queue *q)
{
    return (q->rear+q->size-q->front+1)%q->size;
}

void display(queue *q)
{
    printf("Queue: ");
    if(isEmpty(q))
    {
        printf("queue is empty.\n");
        return;
    }
    int x=q->front;
    if(q->front>q->rear+1)
    {
        for(int i=q->front;i<q->size;i++)
        {
            printf("%d ",q->a[i]);
        }
        x=0;
    }
    for(int i=x;i<=q->rear;i++)
    {
        printf("%d ",q->a[i]);
    }
    printf("\n");
    return;
}

int main()
{
    queue *q=create(200);
    int type=0,n_rides=0,n_adult=0,n_child=0,n_vip_adult=0,n_vip_child=0;
    printf("Enter the type of rider:\n1. Adult\n2. Child\n3. VIP Adult\n4. VIP Child\n5. End\n");
    while(type!=5)
    {
        scanf("%d",&type);
        if(type==1) n_adult++,enqueue(q,type);
        else if(type==2) n_child++,enqueue(q,type);
        else if(type==3) n_vip_adult++,enqueue_vip(q,type);
        else if(type==4) n_vip_child++,enqueue_vip(q,type);
        else if(type!=5) printf("Wrong Input!\n");
        if(size(q)>=20)
        {
            n_rides++;
            for(int i=0;i<20;i++) dequeue(q);
            printf("New ride processed.\n");
        }
        else display(q);
    }
    printf("Total number of rides: %d\n",n_rides);
    printf("Total number of Children: %d\n",n_child+n_vip_child);
    printf("Total number of Adults: %d\n",n_adult+n_vip_adult);
    printf("Total number of VIPs: %d\n",n_vip_adult+n_vip_child);
    printf("Total number of riders remaining: %d\n",size(q));
    return 0;
}