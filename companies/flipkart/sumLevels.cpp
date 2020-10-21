#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n;

int helper()
{
    int ans=INT_MIN;
    vector<bool> vis(n,false);
    queue<int> q;
    q.push(0);
    vis[0]=true;
    while(!q.empty())
    {
        int sum=0,sz=q.size();
        while(sz--)
        {
            int u=q.front();q.pop();
            sum+=(u+1);
            for(int v:adj[u])
            {
                if(!vis[v])
                {
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        ans=max(ans,sum);
    }
    return ans;
}

void solve()
{
    int i,x,y;
    cin>>n;
    adj.resize(n);
    for(i=0;i<n-1;i++)
    {
        cin>>x>>y;x--;y--;// 0 based indx
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<helper()<<endl;
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