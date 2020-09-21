#include <bits/stdc++.h>
using namespace std;

int n,m,t=0;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> disc,low;
unordered_set<int> ans; // articulation points

void dfs(int u,int parent)
{
    vis[u]=true;
    disc[u]=low[u]=t++;
    int child=0;
    for(int v:adj[u])
    {
        if(!vis[v])
        {
            child++;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(parent==-1 and child>1)
            ans.insert(u);
            if(parent!=-1 and low[v]>=disc[u])
            ans.insert(u);
        }
        else if(v!=parent)
        low[u]=min(low[u],disc[v]);
    }
}

void Articulation()
{
    vis=vector<bool> (n,false);
    low=vector<int> (n);
    disc=vector<int> (n);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        dfs(i,-1);
    }
    cout<<"Articulation points are: ";
    for(auto x:ans)
    cout<<x<<" ";
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
    Articulation();
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