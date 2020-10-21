#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

struct DSU
{
    int N;
    vector<int> parent,sz;
    DSU(int n)
    {
        N=n;
        parent.resize(n);
        sz.resize(n);
        for(int i=0;i<N;i++)
        {
            parent[i]=i;
            sz[i]=1;
        }
    }
    int find(int a)
    {
        if(a==parent[a])
            return a;
        return parent[a]=find(parent[a]);
    }
    int merge(int a,int b)
    {
        a=find(a);
        b=find(b);
        if(a!=b)
        {
            if(sz[a]<sz[b])
                swap(a,b);
            parent[b]=a;
            sz[a]+=sz[b];
        }
    }
};

void kruskals(int n,vector<pair<int,pii>> edges)
{
    DSU st(n);
    sort(edges.begin(),edges.end());
    for(auto e:edges)
    {
        int w=e.first;
        int u=e.second.first;
        int v=e.second.second;
        int ru=st.find(u);
        int rv=st.find(v);
        if(ru!=rv)
        {
            cout<<u<<" - "<<v<<" : "<<w<<endl;
            st.merge(ru,rv);
        }
    }
}

void solve()
{
    int i,j,n,m;
    cin>>n>>m;
    vector<pair<int,pii>> edges;
    for(i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;  // when edges are 0 based
        edges.push_back({w,{x,y}});
    }
    kruskals(n,edges);
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