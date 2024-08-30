#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
	int *items;
	int front,rear;
};

typedef struct Queue queue;

queue* createQueue(int n)
{
	queue* q=malloc(sizeof(queue));
    q->size=n;
    q->items=malloc(n*sizeof(int));
	q->front=-1;
	q->rear=-1;
	return q;
}

int isEmptyQueue(queue* q)
{
	if(q->rear==-1) return 1;
	else return 0;
}

void enqueue(queue* q,int value)
{
	if(q->rear==q->size-1)
	printf("\nQueue is Full!!");
	else
    {
	    if(q->front==-1) q->front=0;
	    q->rear++;
	    q->items[q->rear]=value;
	}
}

int dequeue(queue* q)
{
	int item;
	if(isEmptyQueue(q))
    {
	    printf("Queue is empty");
	    item=-1;
	}
    else
    {
	    item=q->items[q->front];
	    q->front++;
	    if(q->front>q->rear) q->front=q->rear=-1;
	}
	return item;
}

struct Stack
{
    int size;
    int *a;
    int top;
};

typedef struct Stack stack;

stack* createStack(int n)
{
    stack* s=malloc(sizeof(stack));
    s->size=n;
    s->a=(int*)malloc(n*sizeof(int));
    s->top=-1;
    return s;
}

int isEmptyStack(stack *s)
{
    return s->top==-1;
}

int isFull(stack *s)
{
    return s->top==s->size-1;
}

void push(stack *s,int x)
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

int pop(stack *s)
{
    if(isEmptyStack(s))
    {
        printf("Stack underflow.\n");
        return 0;
    }
    s->top--;
    return s->a[s->top+1];
}

int peek(stack *s)
{
    if(isEmptyStack(s))
    {
        printf("No elements to peek.\n");
        return 0;
    }
    return s->a[s->top];
}

int size(stack *s)
{
    return s->top+1;
}

void display(stack *s)
{
    if(isEmptyStack(s))
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

struct Node
{
	int vertex;
	struct Node* next;
};

typedef struct Node node;

node* createNode(int n)
{
    node* newNode=malloc(sizeof(node));
	newNode->vertex=n;
	newNode->next=NULL;
	return newNode;
}

struct Graph
{
	int numVertices;
	node** adjLists;
	int* visited;
};

typedef struct Graph graph;

graph* createGraph(int vertices)
{
	graph* grp=malloc(sizeof(graph));
	grp->numVertices=vertices;
	grp->adjLists=malloc(vertices*sizeof(node*));
	grp->visited=malloc(vertices*sizeof(int));

	int i;
	for(i=0;i<vertices;i++)
    {
	    grp->adjLists[i]=NULL;
	    grp->visited[i]=0;
	}
	return grp;
}

void addEdge(graph* grp,int src,int dest)
{
	node* newNode=createNode(dest);
	newNode->next=grp->adjLists[src];
	grp->adjLists[src]=newNode;

	newNode=createNode(src);
	newNode->next=grp->adjLists[dest];
	grp->adjLists[dest]=newNode;
}

void BFS(graph* grp,int startVertex)
{
	queue* q=createQueue(100);
	grp->visited[startVertex]=1;
	enqueue(q,startVertex);
	while(!isEmptyQueue(q))
    {
	    int currentVertex=dequeue(q);
	    printf("%d ",currentVertex);
	    node* temp=grp->adjLists[currentVertex];
	    while(temp)
        {
	        int adjVertex=temp->vertex;
	        if (grp->visited[adjVertex]==0)
            {
	            grp->visited[adjVertex]=1;
	            enqueue(q,adjVertex);
	        }
	        temp=temp->next;
	    }
	}
}

void DFS(graph *grp,int startVertex)
{
    stack *s=createStack(100);
    grp->visited[startVertex]=1;
    push(s,startVertex);
    while (!isEmptyStack(s))
    {
        int currentVertex=pop(s);
	    printf("%d ",currentVertex);
        node* temp=grp->adjLists[currentVertex];
	    while(temp)
        {
	        int adjVertex=temp->vertex;
	        if (grp->visited[adjVertex]==0)
            {
	            grp->visited[adjVertex]=1;
	            push(s,adjVertex);
	        }
	        temp=temp->next;
	    }
    }
}

void initialize(graph* grp)
{
    for(int i=0;i<grp->numVertices;i++)
    {
        grp->visited[i]=0;
    }
}

int main()
{
	graph* grp=createGraph(7);
	addEdge(grp,0,1);
	addEdge(grp,0,2);
	addEdge(grp,0,6);
	addEdge(grp,2,6);
	addEdge(grp,0,3);
	addEdge(grp,0,5);
	addEdge(grp,3,5);
	addEdge(grp,3,4);
	addEdge(grp,4,5);
    printf("BFS: ");
	BFS(grp,0);
    initialize(grp);
    printf("\nDFS: ");
	DFS(grp,0);
	return 0;
}