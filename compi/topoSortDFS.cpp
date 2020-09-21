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
stack<int> st;

void topoSortHelper(int v,vector<bool> &vis)
{
    vis[v]=true;
    for(auto it:adj[v])
    {
        if(!vis[it])
            topoSortHelper(it,vis);
    }
    st.push(v);
}

void topoSortDFS()
{
    int i,n=adj.size();
    vector<bool> vis(n,false);
    for(i=0;i<n;i++)
    {
        if(!vis[i])
            topoSortHelper(i,vis);
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
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
        // adj[y].pb(x);  as Topo Sort is for Directed Edges
    }
    topoSortDFS();
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