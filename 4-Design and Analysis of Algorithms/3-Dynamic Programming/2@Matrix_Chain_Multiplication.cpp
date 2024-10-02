#include <bits/stdc++.h>
using namespace std;

void minMulti(int* p,int n,int** m,int** s)
{
	for(int i=0;i<n;i++) m[i][i]=0;
	for(int l=1;l<n;l++)
	{
	    for(int i=0;i<n-l;i++)
	    {
	        int j=i+l;
	        m[i][j]=INT_MAX;
	        for(int k=i;k<j;k++)
	        {
	            int q=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
	            if(q<m[i][j])
	            {
	                m[i][j]=q;
	                s[i][j]=k;
	            }
	        }
	    }
	}
	return;
}

void optimalParens(int** s,int i,int j)
{
    if(i==j) cout<<char('A'+i);
    else
    {
        cout<<'(';
        optimalParens(s,i,s[i][j]);
        optimalParens(s,s[i][j]+1,j);
        cout<<')';
    }
    return;
}

int main()
{
    int n;
    cin>>n;
	int p[n+1];
	cin>>p[0];
	for(int i=1;i<n;i++)
	{
	    cin>>p[i];
	    cin>>p[i];
	}
	cin>>p[n];
	int **m=new int*[n],**s=new int*[n];
	for(int i=0;i<n;i++)
	{
	    m[i]=new int[n];
	    s[i]=new int[n];
	}
    minMulti(p,n,m,s);
    optimalParens(s,0,n-1);
	return 0;
}