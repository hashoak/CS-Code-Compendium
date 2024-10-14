#include <bits/stdc++.h>
using namespace std;

void search(string T,string P,int n,int m,int d,int q)
{
	int h=1,p=0,t=0,i,j;
    bool f=0;
	for(i=0;i<m-1;i++) h=(h*d)%q;
	for(i=0;i<m;i++)
    {
		p=(d*p+P[i])%q;
		t=(d*t+T[i])%q;
	}
	for(i=0;i<=n-m;i++)
    {
		if(p==t)
        {
			for(j=0;j<m;j++)
            {
				if(T[i+j]!=P[j]) break;
			}
			if(j==m)
            {
                f=1;
                cout<<"String found in position "<<i+1<<"\n";
            }
		}
		if(i<n-m)
        {
			t=(d*(t-T[i]*h)+T[i+m])%q;
			if(t<0) t+=q;
		}
	}
    if(!f) cout<<"String not found\n";
    return;
}

int main()
{
    int n,m;
    string t,p;
    cin>>n>>t>>m>>p;
	search(t,p,n,m,256,13);
	return 0;
}