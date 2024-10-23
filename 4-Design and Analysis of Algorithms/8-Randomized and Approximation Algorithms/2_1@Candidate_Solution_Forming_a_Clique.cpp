#include<bits/stdc++.h>
using namespace std;

bool clique(int n,int m,int** grp,int* sol)
{
    for(int i=0;i<n;i++)
    {
        if(sol[i])
        {
            for(int j=0;j<n;j++)
            {
                if(sol[j] && i!=j && !grp[i][j]) return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int n;
    cin>>n;
    int **grp=new int*[n];
    for(int i=0;i<n;i++)
    {
        grp[i]=new int[n];
        for(int j=0;j<n;j++) cin>>grp[i][j];
    }
    int m;
    cin>>m;
    int sol[n];
    for(int i=0;i<n;i++) cin>>sol[i];
    clique(n,m,grp,sol) ? cout<<"True":cout<<"False";
    cout<<"\n";
    return 0;
}