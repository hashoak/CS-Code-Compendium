#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Queue
{
    int size;
    char *a;
    int front,rear;
};

typedef struct Queue queue;

queue* create(int n)
{
    queue* q=malloc(sizeof(queue));
    q->size=n;
    q->a=(char*)malloc(n*sizeof(char));
    q->front=-1;
    q->rear=-1;
    return q;
}

int isEmpty(queue *q)
{
    return q->front==-1;
}

int isFull(queue *q)
{
    return (q->rear+1)%q->size==q->front;
}

void enqueue(queue *q,char x)
{
    if(isFull(q))
    {
        printf("Queue overflow.\n");
        return;
    }
    if(q->front==-1) q->front++;
    q->rear=(q->rear+1)%q->size;
    q->a[q->rear]=x;
    return;
}

char dequeue(queue *q)
{
    if(isEmpty(q))
    {
        printf("Queue underflow.\n");
        return -1;
    }
    if(q->front==q->rear) q->front=-1,q->rear=-1;
    else q->front=(q->front+1)%q->size;
    return q->a[(q->front+q->size-1)%q->size];
}

char peek(queue *q)
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
    if(isEmpty(q))
    {
        printf("Queue is empty.\n");
        return;
    }
    // printf("Queue: ");
    if(q->rear>=q->front)
    {
        for(int i=q->front;i<=q->rear;i++)
            printf("%c",q->a[i]);
    }
    else
    {
        for(int i=q->front;i<q->size;i++)
            printf("%c",q->a[i]);
 
        for(int i=0;i<=q->rear;i++)
            printf("%c",q->a[i]);
    }
    printf("\n");
    return;
}

void print_front_rear(queue *q)
{
    printf("Front: %d, rear: %d\n",q->front,q->rear);
    return;
}

int main()
{
    char *hardDisk=(char*)malloc(200*sizeof(char));
    printf("Enter the data present in the hard disk:\n");
    scanf("%s",hardDisk);
    printf("\n");
    char *dvd=(char*)malloc(200*sizeof(char));
    strcpy(dvd,"");
    queue *buffer=create(10);
    int size_disk=strlen(hardDisk);
    int i=0,w=0,b=0;
    while(i<size_disk)
    {
        printf("---Writing Process---\n");
        w++;
        while(!isFull(buffer) && i<size_disk)   // Writing process
        {
            print_front_rear(buffer);
            printf("Old data: ");
            display(buffer);
            printf("Newly written data: %c\n",hardDisk[i]);
            printf("\n");
            enqueue(buffer,hardDisk[i]);
            i++;
        }
        printf("---Burning Process---\n");
        b++;
        while(!isEmpty(buffer))     // Burning process
        {
            print_front_rear(buffer);
            char t=peek(buffer);
            printf("Old data: ");
            display(buffer);
            printf("Newly burnt data: %c\n",t);
            printf("\n");
            strncat(dvd,&t,1);
            dequeue(buffer);
        }
    }
    printf("Data in DVD: %s\n",dvd);
    printf("Number of Writing processes: %d\n",w);    // Displays the total number of
    printf("Number of Burning processes: %d\n",b);    // writing and burning processes
    return 0;
}