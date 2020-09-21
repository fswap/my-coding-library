#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj;
int n;
vector<int> order,indeg;

void topoSort()
{
    int i;
    queue<int> q;
    for(i=0;i<n;i++)
    {
        if(indeg[i]==0)
        q.push(i);
    }
    while(!q.empty())
    {
        int u=q.front();q.pop();
        order.push_back(u);
        for(auto p:adj[u])
        {
            int v=p.first;
            indeg[v]--;
            if(indeg[v]==0)
            q.push(v);
        }
    }
}

void DAG(int src)
{
    vector<int> dis(n,INT_MAX);
    dis[src]=0;
    topoSort();
    for(auto u:order)
    {
        for(auto p:adj[u])
        {
            int v=p.first,w=p.second;
            if(dis[u]!=INT_MAX and dis[u]+w<dis[v])
            dis[v]=dis[u]+w;
        }
    }
    cout<<endl;
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
    int e;
    cin>>n>>e;
    adj=vector<vector<pair<int,int>>> (n);
    indeg=vector<int> (n,0);
    while(e--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        indeg[v]++;
    }
    DAG(1); // 1 is the source here
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