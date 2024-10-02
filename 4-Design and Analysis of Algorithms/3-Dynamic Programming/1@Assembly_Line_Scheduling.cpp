
#include <bits/stdc++.h>
using namespace std;
#define NUM_LINE 2

int carAssembly(int **a,int **t,int *e, int *x,int n)
{
    int T1[n],T2[n],i;
    T1[0]=e[0]+a[0][0];
    T2[0]=e[1]+a[1][0];
    for(i=1;i<n;++i)
    {
        T1[i]=min(T1[i-1]+a[0][i],T2[i-1]+t[1][i-1]+a[0][i]);
        T2[i]=min(T2[i-1]+a[1][i],T1[i-1]+t[0][i-1]+a[1][i]);
    }
    return min(T1[n-1]+x[0],T2[n-1]+x[1]);
}
int main()
{
    int n;
    cin>>n;
    int **a=new int*[2],**t=new int*[2];
    for(int i=0;i<2;i++)
    {
        a[i]=new int[n];
        for(int j=0;j<n;j++) cin>>a[i][j];
    }
    for(int i=0;i<2;i++)
    {
        t[i]=new int[n-1];
        for(int j=0;j<n-1;j++) cin>>t[i][j];
    }
    int e[2],x[2];
    cin>>e[0]>>e[1]>>x[0]>>x[1];
    cout<<carAssembly(a,t,e,x,n);
    return 0;
}
