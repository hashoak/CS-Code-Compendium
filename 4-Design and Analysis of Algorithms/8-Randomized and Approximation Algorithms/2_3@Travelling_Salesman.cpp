#include<bits/stdc++.h>
using namespace std;

int findNearestCity(int n,int**graph,int currCity,bool* visited)
{
    int nearestCity=-1,minDist=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && graph[currCity][i]<minDist)
        {
            nearestCity=i;
            minDist=graph[currCity][i];
        }
    }
    return nearestCity;
}

void printApproxShortestTour(int n,int** graph)
{
    bool visited[n]={0};
    int currCity=0;
    visited[currCity]=1;
    cout<<"0 ";

    for(int i=0;i<n-1;i++)
    {
        currCity=findNearestCity(n,graph,currCity,visited);
        visited[currCity]=1;
        cout<<currCity<<" ";
    }
    cout<<"0";
    return;
}

int main()
{
    int n;
    cin>>n;
    int **graph=new int*[n];
    for(int i=0;i<n;i++)
    {
        graph[i]=new int[n];
        for(int j=0;j<n;j++)cin>>graph[i][j];
    }
    printApproxShortestTour(n,graph);
    return 0;
}