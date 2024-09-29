#include<bits/stdc++.h>
using namespace std;

void win_lose(int *a,int s,int e,int* win,int* lose)
{
    if(s==e) *win=s,*lose=s;
    else if(s==e-1)
    {
        if(a[s]>a[e]) *win=s,*lose=e;
        else *win=e,*lose=s;
    }
    else
    {
        int m=(s+e)/2;
        int *win1=new int,*lose1=new int,*win2=new int,*lose2=new int;
        win_lose(a,s,m,win1,lose1);
        win_lose(a,m+1,e,win2,lose2);
        *win=max(*win1,*win2);
        *lose=min(*lose1,*lose2);
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int *win=new int;
    int *lose=new int;
    win_lose(a,0,n-1,win,lose);
    cout<<"Winner "<<*win+1<<"\nWorst player "<<*lose+1<<"\n";
    return 0;
}