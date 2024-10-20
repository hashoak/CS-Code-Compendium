#include<iostream>
using namespace std;

int direction(int* pi,int* pj,int *pk)
{
    return (pj[0]-pi[0])*(pk[1]-pi[1])-(pk[0]-pi[0])*(pj[1]-pi[1]);
}

bool on_segment(int* pi,int* pj,int* pk)
{
    return (min(pi[0],pj[0])<=pk[0] and pk[0]<=max(pi[0],pj[0]))
    and (min(pi[1],pj[1])<=pk[1] and pk[1]<=max(pi[1],pj[1]));
}

bool intersect(int** p)
{
    int d0=direction(p[1],p[2],p[3]);
    int d1=direction(p[2],p[3],p[0]);
    int d2=direction(p[3],p[0],p[1]);
    int d3=direction(p[0],p[1],p[2]);
    if(((d0>0 and d1<0) or (d0<0 and d1>0))
    and ((d2>0 and d3<0) or (d2<0 and d3>0)))
        return 1;
    else if(d0==0 and on_segment(p[1],p[2],p[3])) return 1;
    else if(d1==0 and on_segment(p[2],p[3],p[0])) return 1;
    else if(d2==0 and on_segment(p[3],p[0],p[1])) return 1;
    else if(d3==0 and on_segment(p[0],p[1],p[2])) return 1;
    else return 0;
}

int main()
{
    int** p=new int*[4];
    for(int i=0;i<4;i++)
    {
        p[i]=new int[2];
        cin>>p[i][0]>>p[i][1];
    }
    if(intersect(p)) cout<<"Line segments intersect\n";
    else cout<<"Line segments do not intersect\n";
    return 0;
}