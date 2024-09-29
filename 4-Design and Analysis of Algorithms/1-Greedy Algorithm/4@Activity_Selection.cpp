#include <bits/stdc++.h>
using namespace std;

void maxActivities(int s[],int f[],int n,int k)
{
	int i,j;
	i=0,k--;
	cout<<i<<" ";
	for(j=1;k && j<n;j++)
	{
		if(s[j]>=f[i])
		{
			cout<<j<<" ";
			i=j;
			k--;
		}
	}
}

int main()
{
    int n,k;
    cin>>n>>k;
	int s[n],f[n];
	for(auto &i:s) cin>>i;
	for(auto &i:f) cin>>i;

    maxActivities(s,f,n,k);
	return 0;
}