#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> prio;
int n,sum,cnt;

void dfs(int u)
{
    vis[u]=true;
    cnt++;
    sum+=prio[u];
    for(int v:adj[u])
    {
        if(!vis[v])
        dfs(v);
    }
}

int helper()
{
    int i,ans,mx=0;
    vis=vector<bool> (n,false);
    for(i=0;i<n;i++)
    {
        if(!vis[i])
        {
            sum=0;
            cnt=0;
            dfs(i);
            //cout<<"Sum and Count in component is "<<sum<<" and "<<cnt<<endl;
            if(sum>mx)
            {
                ans=cnt;
                mx=sum;
            }
        }
    }
    return ans;
}

void solve()
{
    int i,j,m;
    cin>>n>>m;
    adj=vector<vector<int>> (n);
    while(m--)
    {
        int x,y;
        cin>>x>>y;x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    prio=vector<int> (n);
    for(i=0;i<n;i++)
    cin>>prio[i];
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