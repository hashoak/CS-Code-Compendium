#include<bits/stdc++.h>
using namespace std;

void LCS(string x,string y,int n,int m,int** c,int** b)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(!i or !j) c[i][j]=0;
            else if(x[i-1]==y[j-1]) c[i][j]=c[i-1][j-1]+1,b[i][j]=0;
            else if(c[i][j-1]>c[i-1][j]) c[i][j]=c[i][j-1],b[i][j]=-1;
            else c[i][j]=c[i-1][j],b[i][j]=1;
        }
    }
}

void traceLCS(string x,int** b,int i,int j)
{
    if(!i or !j) return;
    if(b[i][j]==0)
    {
        traceLCS(x,b,i-1,j-1);
        cout<<x[i-1];
    }
    else if(b[i][j]==1) traceLCS(x,b,i-1,j);
    else traceLCS(x,b,i,j-1);
}

int main()
{
    int n,m;
    cin>>n>>m;
    string x,y;
    cin>>x>>y;
    int** c=new int*[n+1],** b=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        c[i]=new int[m+1];
        b[i]=new int[m+1];
    }
    LCS(x,y,n,m,c,b);
    traceLCS(x,b,n,m);
    cout<<"\n";
    return 0;
}