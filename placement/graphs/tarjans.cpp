#include <bits/stdc++.h>
using namespace std;

int n,m,t=0;
vector<vector<int>> adj;
stack<int> st;
vector<int> disc,low;
vector<bool> inStack;

void dfs(int u)
{
    disc[u]=low[u]=t++;
    st.push(u);
    inStack[u]=true;
    for(auto v:adj[u])
    {
        if(disc[v]==-1)
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(inStack[v])
        low[u]=min(low[u],disc[v]);
    }
    if(low[u]==disc[u])
    {
        vector<int> scc;
        while(st.top()!=u)
        {
            int tp=st.top();st.pop();
            scc.push_back(tp);
            inStack[tp]=false;
        }
        // when top is u
        int tp=st.top();st.pop();
        scc.push_back(tp);
        inStack[tp]=false;
        //print the scc vector
        for(auto x:scc)
        cout<<x<<" ";
        cout<<endl;
    }
}

void SCC()
{
    disc=vector<int> (n,-1);
    low=vector<int> (n,-1);
    inStack=vector<bool> (n,false);
    cout<<"SCCs in the graphs are"<<endl;
    for(int i=0;i<n;i++)
    {
        if(disc[i]==-1)
        dfs(i);
    }
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