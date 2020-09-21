#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define vll vector<pair<ll,ll>>
#define matrix(x) vector<vector<x>>
#define ff first
#define ss second
#define mp make_pair
const int INF = 1e9;
const int MOD = 1e9 + 7;

struct Point
{
    int x,y;
};

int orientation(Point p,Point q,Point r)
{
    int val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
    if(val==0) // collinear, in a line
    return 0;
    else if(val>0)  // Clockwise (like p,r,q) right turn from r to reach q
    return 1;
    else       // Anticlockwise (like p,q,r) left turn from r to reach q
    return 2;
}

void convexHull(Point points[],int n)
{
    int i,l=0;
    vector<Point> hull;
    for(i=1;i<n;i++)
        if(points[i].x<points[l].x)
            l=i;
    int p=l,q;
    do
    {
        hull.pb(points[p]);
        q=(p+1)%n;
        for(i=0;i<n;i++)
            if(orientation(points[p],points[i],points[q])==2)
                q=i;
        p=q;
    } while (p!=l);

    for(auto it:hull)
    cout<<"( "<<it.x<<" , "<<it.y<<" )"<<endl;
}

void solve()
{
	Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},
                      {3, 0}, {0, 0}, {3, 3}};
    int n = sizeof(points)/sizeof(points[0]);
    convexHull(points,n);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	t=1;
	//cin>>t;
	while(t--)
		solve();
}