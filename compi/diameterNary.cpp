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

matrix(pii) adj;
vi dis;

void bfs(int src)
{
    queue<int> q;
    int n=adj.size();
    dis=vi (n,-1);
    q.push(src);
    dis[src]=0;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(auto v:adj[u])
        {
            if(dis[v.ff]==-1)
            {
                dis[v.ff]=dis[u]+v.ss;
                q.push(v.ff);
            }
        }
    }
}

void solve()
{
	int n,i,cost;
    cin>>n;
    adj=matrix(pii) (n+1);
    for(i=0;i<n-1;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        adj[x].pb({y,z});
        adj[y].pb({x,z});
    }
    bfs(1);
    int pos=max_element(dis.begin()+1,dis.end())-dis.begin();
    bfs(pos);
    int ds=*(max_element(dis.begin()+1,dis.end()));
    cout<<ds<<endl;
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