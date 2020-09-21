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

void check(int n,vector<pii> edges)
{
    DSU st(n);
    for(auto e:edges)
    {
        int x=st.find(e.first);
        int y=st.find(e.second);
        if(x==y)
        {
            cout<<"Cyclic"<<endl;
            return;
        }
        st.merge(x,y);
    }
    cout<<"Not Cyclic"<<endl;
}

void solve()
{
    int n,e,i,flag=0;
    cin>>n>>e;
    vector<pii> edges;
    for(i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        edges.push_back({x,y});
    }
    check(n,edges);
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