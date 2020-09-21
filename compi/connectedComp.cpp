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
int ans;

void helper(int v,vector<bool> &vis)
{
    vis[v]=true;
    for(auto it:adj[v])
    {
        if(!vis[it])
            helper(it,vis);
    }
}

void dfs()
{
    int i,n=adj.size();
    vector<bool> vis(n,false);
    for(i=0;i<n;i++)
    {
        if(!vis[i])
        {
            helper(i,vis);
            ans++;
        }
    }
}

void solve()
{
	int i,n,e;
    cin>>n>>e;             // n- number of vertex,  e- number of edges
    adj.clear();ans=0;
    adj.resize(n);
    for(i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs();
    cout<<ans<<endl;
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