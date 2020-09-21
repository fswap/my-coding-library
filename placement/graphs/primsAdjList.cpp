#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
const int INF=1e9;

vector<vector<pii>> adj;
int n;

void prims()
{
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    vector<bool> mst(n,false);
    vector<int> key(n,INF);
    vector<int> parent(n,-1);
    pq.push({0,0}); // (weight,src)
    key[0]=0;
    mst[0]=true;
    while(!pq.empty())
    {
        int u=pq.top().second;pq.pop();
        for(auto p:adj[u])
        {
            int v=p.first;
            int w=p.second;
            if(!mst[v] and w<key[v])
            {
                key[v]=w;
                pq.push({key[v],v});
                parent[v]=u;
                mst[u]=true;
            }
        }
    }
    for(int i=1;i<n;i++)
    cout<<parent[i]<<" - "<<i<<endl;
}

void solve()
{
    int i,j,e;
    cin>>n>>e;
    adj=vector<vector<pii>> (n);
    for(i=0;i<e;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    prims();
}

int32_t main()
{
    int t;
    t=1;
    //cin>>t;
    while(t--)
        solve();
}