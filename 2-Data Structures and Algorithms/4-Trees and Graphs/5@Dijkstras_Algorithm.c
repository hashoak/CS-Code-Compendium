#include<stdio.h>
#include<stdlib.h>
#define inf __INT32_MAX__

struct Graph
{
    int v;
    int **weights;
};

typedef struct Graph graph;

graph* createGraph(int n)
{
    graph *new=(graph*)malloc(sizeof(graph));
    new->v=n;
    new->weights=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
    {
        new->weights[i]=(int*)malloc(n*sizeof(int));
        for(int j=0;j<n;j++) new->weights[i][j]=0;
    }
    return new;
}

void addEdge(graph *grp,int a,int b,int wt)
{
    grp->weights[a][b]=grp->weights[b][a]=wt;
}

void Dijkstra(graph *grp,int start)
{
    int n=grp->v;
    int dist[n],sptSet[n];
    for(int i=0;i<n;i++) dist[i]=inf,sptSet[i]=0;
    dist[start]=0;

    for(int i=0;i<n-1;i++)
    {
        int u,min=inf;
        for(int j=0;j<n;j++)
        {
            if(sptSet[j]==0 && dist[j]<=min) min=dist[j],u=j;
        }
        sptSet[u]=1;
        for(int j=0;j<n;j++)
        {
            if(!sptSet[j] && grp->weights[u][j] && dist[u]!=inf && dist[u]+grp->weights[u][j]<dist[j])
                dist[j]=dist[u]+grp->weights[u][j];
        }
    }
    
    for(int i=0;i<n;i++) printf("Distance of vertex %d from Source: %d\n",i,dist[i]);
    return;
}

int main()
{
    int v=9;
    graph *grp=createGraph(9);

    addEdge(grp,0,1,4);
    addEdge(grp,0,7,8);
    addEdge(grp,1,7,11);
    addEdge(grp,1,2,8);
    addEdge(grp,7,8,7);
    addEdge(grp,7,6,1);
    addEdge(grp,2,8,2);
    addEdge(grp,8,6,6);
    addEdge(grp,2,3,7);
    addEdge(grp,2,5,4);
    addEdge(grp,6,5,2);
    addEdge(grp,3,5,14);
    addEdge(grp,3,4,9);
    addEdge(grp,5,4,10);

    Dijkstra(grp,0);

    return 0;
}