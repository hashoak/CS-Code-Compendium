#include <bits/stdc++.h>
using namespace std;

struct Point
{
	int x,y;
};

int direction(Point p,Point q,Point r)
{
    return (q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
}

void convexHull(Point points[],int n)
{
	if(n<3) return;
    int mx=0,my=0;
    for(int i=0;i<n;i++)
    {
        if(points[i].x<0) mx=min(mx,points[i].x);
        if(points[i].y<0) my=min(my,points[i].y);
    }
    for(int i=0;i<n;i++)
    {
        points[i].x-=mx,points[i].y-=my;
        cout<<points[i].x<<" "<<points[i].y<<"\n";
    }
	vector<Point> hull;
	int l=0;
	for(int i=1;i<n;i++) if(points[i].x<points[l].x) l=i;
	int p=l,q;
	do
	{
		hull.push_back(points[p]);
		q=(p+1)%n;
		for(int i=0;i<n;i++)
        {
            cout<<n<<" "<<p<<" "<<q<<" "<<i<<"\n";
    		if(p!=i and i!=q and direction(points[p],points[i],points[q])<=0)
                q=i;
        }
		p=q;
	} while(p!=l);
	for(int i=hull.size()-1;i>=0;i--)
		cout<<hull[i].x<<" "<<hull[i].y<<"\n";
}

int main()
{
	int n;
    cin>>n;
    Point points[n];
    for(int i=0;i<n;i++)
    {
        cin>>points[i].x>>points[i].y;
    }
	convexHull(points,n);
	return 0;
}
