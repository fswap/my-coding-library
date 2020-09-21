#include <bits/stdc++.h>
using namespace std;

int n,m,t=0;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> disc,low;

void dfs(int u,int parent)
{
    vis[u]=true;
    disc[u]=low[u]=t++;
    for(int v:adj[u])
    {
        if(!vis[v])
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>disc[u])
            cout<<"( "<<u<<" , "<<v<<" ) ";
        }
        else if(v!=parent)
        low[u]=min(low[u],disc[v]);
    }
}

void Bridge()
{
    vis=vector<bool> (n,false);
    low=vector<int> (n);
    disc=vector<int> (n);
    cout<<"Bridge Vertices are: ";
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        dfs(i,-1);
    }
    cout<<endl;
}

void solve()
{
    cin>>n>>m;
    adj=vector<vector<int>> (n);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    Bridge();
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