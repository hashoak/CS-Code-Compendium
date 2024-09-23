#include<bits/stdc++.h>
using namespace std;

struct Item
{
    float wt,prior;
    int idx;
};
typedef struct Item item;

void knapSack(item x[],int n,int w,bool* a)
{
    item t;
    for(int i=n;i>1;i--)
    {
        for(int j=0;j<i-1;j++)
        {
            if(x[j].prior<x[j+1].prior)
            {
                t=x[j],x[j]=x[j+1],x[j+1]=t;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(w>=x[i].wt) a[x[i].idx]=1,w-=x[i].wt;
        else a[x[i].idx]=0;
    }
    return;
}

int main()
{
    int n,w;
    cin>>n>>w;
    item* x=new item[n];
    bool a[n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i].wt;
        x[i].idx=i;
    }
    for(int i=0;i<n;i++) cin>>x[i].prior;
    knapSack(x,n,w,a);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}