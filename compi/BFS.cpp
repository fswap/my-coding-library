#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define matrix(x) vector<vector<x>>
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a, b, sizeof a)
#define ff first
#define ss second
#define mp make_pair
const int INF = 1e9;
const int MOD = 1e9 + 7; 

matrix(int) adj;

void bfs(int src)
{
    queue<int> q;
    int n=adj.size();
    vi dis(n,-1);
    q.push(src);
    dis[src]=0;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        if(u==n)
        {
            cout<<dis[u]<<endl;
            return;
        }
        for(auto v:adj[u])
        {
            if(dis[v]==-1)
            {
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}

void solve()
{
	int n,e,i;
    cin>>n>>e;
    adj=matrix(int) (n+1);
    for(i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    bfs(1);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	//t=1;
	cin>>t;
	while(t--)
		solve();
}