#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
const int INF=1e9;

vector<vector<int>> adj;
int n;

int minKey(vector<int> key,vector<bool> mst)
{
    int i,mn=INF,mnv;
    for(i=0;i<n;i++)
    {
        if(!mst[i] and key[i]<mn)
        {
            mn=key[i];
            mnv=i;
        }
    }
    return mnv;
}

void prims()
{
    vector<bool> mst(n,false);
    vector<int> key(n,INF);
    vector<int> parent(n,-1);
    key[0]=0;
    parent[0]=-1;
    for(int len=0;len<n-1;len++)  // mst has n-1 vertices
    {
        int u=minKey(key,mst);
        mst[u]=true;
        for(int v=0;v<n;v++)
        {
            if(adj[u][v] and !mst[v] and adj[u][v]<key[v])
            {
                key[v]=adj[u][v];
                parent[v]=u;
            }
        }
    }
    for(int i=1;i<n;i++)
    cout<<parent[i]<<" - "<<i<<" : "<<adj[parent[i]][i]<<endl;
}

void solve()
{
    int i,j;
    cin>>n;
    adj=vector<vector<int>> (n,vector<int> (n));
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    cin>>adj[i][j];
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