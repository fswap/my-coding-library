#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj,trp;
vector<bool> vis;
stack<int> st;
vector<int> scc;
int n;

void dfs1(int u)
{
    vis[u]=true;
    for(auto v:adj[u])
        if(!vis[v])
        dfs1(v);
    st.push(u);
}

void dfs2(int u)
{
    vis[u]=true;
    for(auto v:trp[u])
        if(!vis[v])
        dfs2(v);
    scc.push_back(u);
}

void SCC()
{
    int i;
    vis=vector<bool> (n,false);
    for(i=0;i<n;i++)
    {
        if(!vis[i])
        dfs1(i);
    }
    vis=vector<bool> (n,false);
    while(!st.empty())
    {
        int u=st.top();st.pop();
        if(!vis[u])
        {
            scc.clear();
            dfs2(u);
            for(auto v:scc)
            cout<<v+1<<" ";
            cout<<endl;
        }
    }
}

void solve()
{
    int e;
    cin>>n>>e;
    adj=vector<vector<int>> (n);
    trp=vector<vector<int>> (n);
    while(e--)
    {
        int u,v;
        cin>>u>>v;u--;v--;
        adj[u].push_back(v);
        trp[v].push_back(u);
    }
    SCC();
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