#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string c,int m,int *lps)
{
    int len=0;
    lps[0]=0;
    for(int i=1;i<m;i++)
    {
        if(c[i]==c[len])
        {
            len++;
            lps[i]=len;
        }
        else
        {
            if(len!=0) len=lps[len-1];
            else lps[i]=0;
        }
    }
}

void KMPSearch(string t,string c,int n,int m)
{
    int lps[m];
    computeLPSArray(c,m,lps);
    int i=0,j=0,b=0;
    while((n-i)>=(m-j))
    {
        if(c[j]==t[i]) j++,i++;
        if(j==m)
        {
            b=1;
            printf("Pattern found at position %d ",i-j+1);
            j=lps[j-1];
        }
        else if(i<n && c[j]!=t[i])
        {
            if(j!=0) j=lps[j-1];
            else i=i+1;
        }
    }
    if(!b) cout<<"Pattern not found\n";
}

int main()
{
    int n,m;
    string t,c;
    cin>>n>>t>>m>>c;
    KMPSearch(t,c,n,m);
    return 0;
}