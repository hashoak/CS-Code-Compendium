#include<bits/stdc++.h>
using namespace std;

void printSubsetSum(int a[],int p[],int n,int d,bool* b,int sum=0,int i=0)
{
    if(i>n or sum>d) return;
    else if(sum==d)
    {
        for(int j=0;j<n;j++) cout<<p[j]<<" ";
        cout<<"\n";
        *b=1;
        return;
    }
    p[i]=1;
    printSubsetSum(a,p,n,d,b,sum+a[i],i+1);
    p[i]=0;
    printSubsetSum(a,p,n,d,b,sum,i+1);
    return;
}

int main()
{
    int n,d;
    cin>>n;
    int a[n],p[n];
    for(int i=0;i<n;i++) {cin>>a[i];p[i]=0;}
    cin>>d;
    bool* b=new bool(0);
    printSubsetSum(a,p,n,d,b);
    if(!(*b))
    {
        cout<<"Solution cannot be found";
    }
    return 0;
}