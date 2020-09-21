#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u,v,w;
};

vector<Edge> edges;
int n,m;

void bellman(int src)
{
    vector<int> dis(n,INT_MAX);
    dis[src]=0;
    for(int i=0;i<n-1;i++)
    {
        for(auto e:edges)
        {
            int u=e.u,v=e.v,w=e.w;
            if(dis[u]!=INT_MAX and dis[v]>dis[u]+w)
            dis[v]=dis[u]+w;
        }
    }
    for(auto e:edges)
    {
        int u=e.u,v=e.v,w=e.w;
        if(dis[u]!=INT_MAX and dis[v]>dis[u]+w)
        {
            cout<<"Graph contains negative weight cycle"<<endl;
            return;
        }
    }
    for(auto d:dis)
    {
        if(d==INT_MAX)
        cout<<"INF ";
        else
        cout<<d<<" ";
    }
    cout<<endl;
}

void solve()
{
    cin>>n>>m;
    while(m--)
    {
        Edge e;
        cin>>e.u>>e.v>>e.w;
        edges.push_back(e);
    }
    bellman(0);
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