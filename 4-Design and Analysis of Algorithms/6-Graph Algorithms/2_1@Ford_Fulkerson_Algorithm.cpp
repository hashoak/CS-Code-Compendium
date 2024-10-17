#include <bits/stdc++.h>
using namespace std;

bool bfs(int** rGraph,int n,int s,int t,int parent[])
{
	bool* visited=new bool[n];
	queue<int> q;
	q.push(s);
	visited[s]=true;
	parent[s]=-1;

	while(!q.empty())
    {
		int u=q.front();
		q.pop();
		for(int v=0;v<n;v++)
        {
			if(visited[v]==false && rGraph[u][v]>0)
            {
				if(v==t)
                {
					parent[v]=u;
					return true;
				}
				q.push(v);
				parent[v]=u;
				visited[v]=true;
			}
		}
	}
	return false;
}

int fordFulkerson(int** graph,int n,int s,int t)
{
	int** rGraph=new int*[n];
    for(int i=0;i<n;i++)
    {
        rGraph[i]=new int[n];
        for(int j=0;j<n;j++) rGraph[i][j]=graph[i][j];
    }

	int u,v;
	int parent[n];
	int max_flow=0;
	while(bfs(rGraph,n,s,t,parent))
    {	
		int path_flow=INT_MAX;
		for(v=t;v!=s;v=parent[v])
        {
			u=parent[v];
			path_flow=min(path_flow,rGraph[u][v]);
		}	
		for(v=t;v!=s;v=parent[v])
        {
			u=parent[v];
			rGraph[u][v]-=path_flow;
			rGraph[v][u]+=path_flow;
		}
		max_flow+=path_flow;
	}
	return max_flow;
}

int main()
{
	int n;
    cin>>n;
	int** graph=new int*[n];
    for(int i=0;i<n;i++)
    {
        graph[i]=new int[n];
        for(int j=0;j<n;j++) cin>>graph[i][j];
    }
	cout<<"Maximum flow is "<<fordFulkerson(graph,n,0,5);
	return 0;
}
