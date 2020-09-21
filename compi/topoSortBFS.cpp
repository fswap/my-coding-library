#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
const int MOD = 1e9 + 7;

vector<vector<int> > adj;

bool topoSortBFS()
{
    int i,n=adj.size();
    vector<int> inDeg(n,0);
    queue<int> q;
    for(i=0;i<n;i++)
    {
        for(auto it:adj[i])
            inDeg[it]++;
    }
    for(i=0;i<n;i++)
    {
        if(!inDeg[i])
            q.push(i);
    }
    while(!q.empty())
    {
        int u=q.front();
        cout<<u<<" ";
        q.pop();
        for(auto v:adj[u])
        {
            inDeg[v]--;
            if(inDeg[v]==0)
            q.push(v);
        }
    }
}

void solve()
{
	int i,n,e;
    cin>>n>>e;             // n- number of vertex,  e- number of edges
    adj.resize(n);
    for(i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y); // as the graph is directed
    }
    topoSortBFS();
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