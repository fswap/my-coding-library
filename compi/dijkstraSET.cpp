#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
const int INF = 1000000000;
const int MOD = 1e9 + 7;

vector<vector<pii>> adj;

void printPath(vector<int> parent,int i)
{
    if(parent[i]==-1)
        return;
    printPath(parent,parent[i]);
    cout<<i<<" -> ";
}

void dijkstra(int src)
{
    int n=adj.size();
    vector<int> dis(n,INF);
    vector<int> parent(n,-1);
    set<pii> st;
    st.insert({0,src});
    dis[src]=0;
    while(!st.empty())
    {
        int u=st.begin()->ss;
        st.erase(st.begin());
        for(auto it:adj[u])
        {
            int v=it.ff;
            int wt=it.ss;
            if(dis[u]+wt<dis[v])
            {
                st.erase({dis[v],v});
                dis[v]=dis[u]+wt;
                parent[v]=u;
                st.insert({dis[v],v});
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        cout<<i<<"\t\t"<<dis[i]<<"\t\t0 -> ";
        printPath(parent,parent[i]); //  done for output to look good, othw func(parent,i) is also right
        cout<<i<<endl;
    }
}

void solve()
{
	int i,n,e;
    cin>>n>>e;             // n- number of vertex,  e- number of edges
    adj.resize(n);
    for(i=0;i<e;i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        adj[x].pb({y,wt});
        adj[y].pb({x,wt});
    }
    dijkstra(0);
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