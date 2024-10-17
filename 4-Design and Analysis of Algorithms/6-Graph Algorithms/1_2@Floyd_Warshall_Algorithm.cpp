#include <bits/stdc++.h>
using namespace std;

#define INF 10000

void printSolution(int **dist,int v)
{
	for (int i=0;i<v;i++)
    {
		for (int j=0;j<v;j++)
        {
			if (dist[i][j]==INF) cout<<"INF"<<" ";
			else cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
}

void floydWarshall(int **dist,int v)
{
	int i, j, k;
	for (k=0;k<v;k++)
    {
		for (i=0;i<v;i++)
        {
			for (j=0;j<v;j++)
            {
				if (dist[i][j]>(dist[i][k]+dist[k][j]) && (dist[k][j]!=INF && dist[i][k]!=INF))
					dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}
	printSolution(dist,v);
}

int main()
{
    int v;
    cin>>v;
	int **graph=new int*[v];
    for(int i=0;i<v;i++)
    {
        graph[i]=new int[v];
        for(int j=0;j<v;j++) cin>>graph[i][j];
    }
	floydWarshall(graph,v);
	return 0;
}