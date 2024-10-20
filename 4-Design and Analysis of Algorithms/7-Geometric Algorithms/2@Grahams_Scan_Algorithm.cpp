#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

struct Point
{
    int x,y;
};

Point p0;

Point nextToTop(stack<Point> &S)
{
    Point p=S.top();
    S.pop();
    Point res=S.top();
    S.push(p);
    return res;
}

int direction(Point p,Point q,Point r)
{
    return (q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
}

int compare(Point vp1,Point vp2)
{
    int o=direction(p0,vp1,vp2);
    if(o==0)
    {
        int dist1=(p0.x-vp1.x)*(p0.x-vp1.x)+(p0.y-vp1.y)*(p0.y-vp1.y);
        int dist2=(p0.x-vp2.x)*(p0.x-vp2.x)+(p0.y-vp2.y)*(p0.y-vp2.y);
        return (dist2>=dist1);
    }
    return (o<0);
}

void convexHull(Point points[],int n)
{
    if(n<3) return;
    int ymin=points[0].y,min=0;
    for(int i=1;i<n;i++)
    {
        int y=points[i].y;
        if((y<ymin) || (ymin==y && points[i].x<points[min].x))
            ymin=points[i].y,min=i;
    }
    p0=points[0];
    points[0]=points[min];
    points[min]=p0;
    sort(points+1,points+n,compare);

    int m=1;
    for(int i=1;i<n;i++)
    {
        while(i<n-1 && direction(p0,points[i],points[i+1])==0) i++;
        points[m]=points[i];
        m++;
    }
    if(m<3) return;
    
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);
    for(int i=3;i<m;i++)
    {
        while(S.size()>1 && direction(nextToTop(S),S.top(),points[i])>=0) S.pop();
        S.push(points[i]);
    }
    
    while(!S.empty())
    {
        Point p=S.top();
        cout<<p.x<<" "<<p.y<<"\n";
        S.pop();
    }
}

int main()
{
    int n=10;
    Point points[n];
    for(int i=0;i<n;i++)
    {
        cin>>points[i].x>>points[i].y;
    }
    convexHull(points,n);
    return 0;
}