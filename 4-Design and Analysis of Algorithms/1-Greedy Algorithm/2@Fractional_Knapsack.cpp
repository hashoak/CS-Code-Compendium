#include<bits/stdc++.h>
using namespace std;

struct Item
{
    float val,wt,ratio;
    int idx;
};
typedef struct Item item;

void knapSack(item** x,int n,float w,float* a)
{
    item* t;
    for(int i=n;i>1;i--)
    {
        for(int j=0;j<i-1;j++)
        {
            if(x[j]->ratio<x[j+1]->ratio)
            {
                t=x[j],x[j]=x[j+1],x[j+1]=t;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(w>=x[i]->wt) a[x[i]->idx]=1,w-=x[i]->wt;
        else if(w) a[x[i]->idx]=w/x[i]->wt;
        else a[x[i]->idx]=0;
    }
    return;
}

int main()
{
    int n,w;
    cin>>w>>n;
    item* x[n];
    float a[n];
    for(int i=0;i<n;i++)
    {
        x[i]=new item;
        cin>>x[i]->wt;
        x[i]->idx=i;
    }
    for(int i=0;i<n;i++)
    {
        cin>>x[i]->val;
        x[i]->ratio=x[i]->val/x[i]->wt;
    }
    knapSack(x,n,w,a);
    for(int i=0;i<n;i++) cout<<fixed<<setprecision(1)<<a[i]<<" ";
    cout<<"\n";
    return 0;
}