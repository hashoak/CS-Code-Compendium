#include <bits/stdc++.h>
using namespace std;

struct Node
{
	Node* parent;
	int pathCost,cost,workerID,jobID;
	bool* assigned;
};

Node* newNode(int x,int y,bool* assigned,Node* parent,int n)
{
	Node* node=new Node;
    node->assigned=new bool[n];
	for(int j=0;j<n;j++) node->assigned[j]=assigned[j];
	node->assigned[y]=true;
	node->parent=parent;
	node->workerID=x;
	node->jobID=y+1;
	return node;
}

int calculateCost(int** costMatrix,int x,int y,bool* assigned,int n)
{
	int cost=0;
	bool available[n]={true};
	for(int i=x+1;i<n;i++)
	{
		int min=INT_MAX,minIndex=-1;
		for(int j=0;j<n;j++)
		{
			if(!assigned[j] && available[j] && costMatrix[i][j]<min)
			{
				minIndex=j;
				min=costMatrix[i][j];
			}
		}
		cost+=min;
		available[minIndex]=false;
	}
	return cost;
}

struct comp
{
	bool operator()(const Node* lhs,const Node* rhs) const
	{
		return lhs->cost > rhs->cost;
	}
};

void printAssignments(Node *min)
{
	if(min->parent==NULL) return;
	printAssignments(min->parent);
	cout<<char(min->workerID+'a')<<":"<<min->jobID<<" ";
}

void findMinCost(int** costMatrix,int n)
{
	priority_queue<Node*,std::vector<Node*>,comp> pq;
	bool* assigned=new bool[n];
    for(int i=0;i<n;i++) assigned[i]=false;
	Node* root=newNode(-1,-1,assigned,NULL,n);
	root->pathCost=root->cost=0;
	root->workerID=-1;
	pq.push(root);
	while(!pq.empty())
	{
	    Node* min=pq.top();
	    pq.pop();
	    int i=min->workerID+1;
	    if(i==n)
	    {
            cout<<min->cost<<"\n";
	    	printAssignments(min);
	    	return;
	    }
	    for(int j=0;j<n;j++)
	    {
	    	if(!min->assigned[j])
	    	{
	    	    Node* child=newNode(i,j,min->assigned,min,n);
	    	    child->pathCost=min->pathCost+costMatrix[i][j];
	    	    child->cost=child->pathCost+calculateCost(costMatrix,i,j,child->assigned,n);
	    	    pq.push(child);
	    	}
	    }
	}
}

int main()
{
    int n;
    cin>>n;
	int** costMatrix=new int*[n];
    for(int i=0;i<n;i++)
    {
        costMatrix[i]=new int[n];
        for(int j=0;j<n;j++) cin>>costMatrix[i][j];
    }
	findMinCost(costMatrix,n);
	return 0;
}
