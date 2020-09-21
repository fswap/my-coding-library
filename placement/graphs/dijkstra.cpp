#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<pair<int,int>>> adj;

void dijkstra(int src)
{
    set<pair<int,int>> st;
    vector<int> dis(n,INT_MAX);
    dis[src]=0;
    st.insert({0,src});
    while(!st.empty())
    {
        int u=(st.begin())->second;
        st.erase(st.begin());
        for(auto p:adj[u])
        {
            int v=p.first,w=p.second;
            if(dis[v]>dis[u]+w)
            {
                st.erase({dis[v],v});
                dis[v]=dis[u]+w;
                st.insert({dis[v],v});
            }
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
    int e;
    cin>>n>>e;
    adj=vector<vector<pair<int,int>>> (n);
    while(e--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijkstra(0);
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