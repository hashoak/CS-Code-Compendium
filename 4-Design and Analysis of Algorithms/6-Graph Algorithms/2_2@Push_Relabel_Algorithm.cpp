#include <iostream>
#include <vector>
using namespace std;

struct Edge
{
	int flow,capacity;
	int u,v;
	Edge(int flow,int capacity,int u,int v)
	{
		this->flow=flow;
		this->capacity=capacity;
		this->u=u;
		this->v=v;
	}
};

struct Vertex
{
	int h,e_flow;
	Vertex(int h,int e_flow)
	{
		this->h=h;
		this->e_flow=e_flow;
	}
};

int overFlowVertex(vector<Vertex>& ver)
{
    int v=ver.size();
	for(int i=1;i<v-1;i++)
	if(ver[i].e_flow>0) return i;
	return -1;
}

class Graph
{
	int v,e;
	vector<Vertex> ver;
	vector<Edge> edge;
	bool push(int u)
    {
        e=edge.size();
        for(int i=0;i<e;i++)
        {
            if(edge[i].u==u)
            {
                if(edge[i].flow==edge[i].capacity) continue;
                if(ver[u].h>ver[edge[i].v].h)
                {
                    int flow=min(edge[i].capacity-edge[i].flow,ver[u].e_flow);
                    ver[u].e_flow-=flow;
                    ver[edge[i].v].e_flow+=flow;
                    edge[i].flow+=flow;
                    updateReverseEdgeFlow(i,flow);
                    return true;
                }
            }
        }
        return false;
    }
	void relabel(int u)
    {
        int mh=INT16_MAX,e=edge.size();
        for(int i=0;i<e;i++)
        {
            if(edge[i].u==u)
            {
                if(edge[i].flow==edge[i].capacity) continue;
                if(ver[edge[i].v].h<mh)
                {
                    mh=ver[edge[i].v].h;
                    ver[u].h=mh+1;
                }
            }
        }
    }
	void preflow(int s)
    {
        ver[s].h=int(ver.size());
        int e=edge.size();
        for(int i=0;i<e;i++)
        {
            if(edge[i].u==s)
            {
                edge[i].flow=edge[i].capacity;
                ver[edge[i].v].e_flow+=edge[i].flow;
                edge.push_back(Edge(-edge[i].flow,0,edge[i].v,s));
            }
        }
    }
	void updateReverseEdgeFlow(int i,int flow)
    {
        int u=edge[i].v,v=edge[i].u,ed=edge.size();
        for(int j=0;j<ed;j++)
        {
            if(edge[j].v==v && edge[j].u==u)
            {
                edge[j].flow-=flow;
                return;
            }
        }
        Edge e=Edge(0,flow,u,v);
        edge.push_back(e);
    }
    
    public:
	Graph(int v)
    {
    	this->v=v;
    	for(int i=0;i<v;i++) ver.push_back(Vertex(0,0));
    }
	void addEdge(int u,int v,int capacity)
    {
    	edge.push_back(Edge(0,capacity,u,v));
    }
	int getMaxFlow(int s,int t)
    {
        preflow(s);
        while(overFlowVertex(ver)!=-1)
        {
            int u=overFlowVertex(ver);
            if(!push(u)) relabel(u);
        }
        return ver.back().e_flow;
    }
};

int main()
{
	int v=6,x;
	Graph g(v);
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cin>>x;
            if(x) g.addEdge(i,j,x);
        }
    }
	int s=0,t=v-1;
	cout<<"Maximum flow is "<<g.getMaxFlow(s,t);
	return 0;
}