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

bool isCyclicBFS()
{
    int i,n=adj.size();
    vector<bool> vis(n,false);
    vector<int> parent(n);
    queue<int> q;
    q.push(0);
    vis[0]=true;
    parent[0]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:adj[u])
        {
            if(!vis[v])
            {
                vis[v]=true;
                parent[v]=u;
                q.push(v);
            }
            else if(v!=parent[u])
            return true;
        }
    }
    return false;
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
        adj[x].pb(y);
        adj[y].pb(x);
    }
    if(isCyclicBFS())
    cout<<"Graph is Cyclic"<<endl;
    else
    cout<<"Not Cyclic"<<endl;
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