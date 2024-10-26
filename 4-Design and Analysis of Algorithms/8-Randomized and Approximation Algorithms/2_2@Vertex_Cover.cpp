#include <bits/stdc++.h>
using namespace std;

class undirected_graph
{
    public:
    vector<int> *vertices;
    int total_vertices;
    undirected_graph(int number_of_vertices)
    {
        total_vertices=number_of_vertices;
        vertices=new vector<int>[number_of_vertices];
    }
    void addEdge(int v,int w)
    {
        vertices[v].push_back(w);
    }
    void solve()
    {
        vector<bool> visited(total_vertices,false);
        for(int u=total_vertices-1;u>=0;u--)
        {
            if(!visited[u])
            {
                for(int v:vertices[u])
                {
                    if(!visited[v])
                    {
                        visited[u]=visited[v]=true;
                        break;
                    }
                }
            }
        }
        for(int i=0;i<total_vertices;i++) cout<<visited[i]<<" ";
    }
};

int main()
{
    int n,x;
    cin>>n;
    undirected_graph g(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>x;
            if(x) g.addEdge(i,j);
        }
    }
    g.solve();
    return 0;
}