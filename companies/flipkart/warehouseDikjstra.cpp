#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<pair<int,int>>> adj;

int dijkstra(int src,int dest)
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
    return dis[dest];
}

void solve()
{
    int i,j,e,k,ans=INT_MAX;
    cin>>n>>k;
    adj=vector<vector<pair<int,int>>> (n);
    vector<int> ware(k);
    for(i=0;i<k;i++)
    cin>>ware[i];
    cin>>e;
    while(e--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(i=0;i<k;i++)
    {
        for(j=i+1;j<k;j++)
        {
            int val=dijkstra(ware[i],ware[j]);
            // cout<<"Compared "<<ware[i]<<" and "<<ware[j]<<" = "<<val<<endl;
            ans=min(ans,val);
        }
    }
    cout<<ans<<endl;
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