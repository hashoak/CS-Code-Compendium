#include <bits/stdc++.h>
using namespace std;

void knapSack(int wt[],int val[],int **f,int n,int w)
{
    for(int i=0;i<=n;i++) 
    {
        for(int j=0;j<=w;j++)
        {
            if(!i or !j) f[i][j]=0;
            else
            {
                if(j<wt[i-1]) f[i][j]=f[i-1][j];
                else f[i][j]=max(f[i-1][j],val[i-1]+f[i-1][j-wt[i-1]]);
            }
        }
    }
	return;
}

void trace(int *t,int **f,int *wt,int i,int j)
{
    if(i==0) return;
    if(f[i][j]==f[i-1][j]) t[i-1]=0,trace(t,f,wt,i-1,j);
    else t[i-1]=1,trace(t,f,wt,i-1,j-wt[i-1]);
}

int main()
{
    int n,w;
    cin>>n>>w;
	int val[n],wt[n];
	for(int i=0;i<n;i++) cin>>wt[i];
	for(int i=0;i<n;i++) cin>>val[i];
    int **f=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        f[i]=new int[w+1];
    }
    knapSack(wt,val,f,n,w);
    int t[n];
    trace(t,f,wt,n,w);
    for(int i=0;i<n;i++) cout<<t[i]<<" ";
    cout<<"\n";
	return 0;
}