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

bool isCyclicHelper(int v,vector<bool> &vis,vector<bool> &inStack)
{
    vis[v]=true;
    inStack[v]=true;
    for(auto it:adj[v])
    {
        if((!vis[it] && isCyclicHelper(it,vis,inStack)) or inStack[it])
                return true;
    }
    inStack[v]=false;
    return false;
}

bool isCyclicDFS()
{
    int i,n=adj.size();
    vector<bool> vis(n,false);
    vector<bool> inStack(n,false);
    for(i=0;i<n;i++)
    {
        if(!vis[i])
        {
            if(isCyclicHelper(i,vis,inStack))
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
        // adj[y].pb(x);   Graph is Directed
    }
    if(isCyclicDFS())
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