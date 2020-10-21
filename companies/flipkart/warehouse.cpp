#include <bits/stdc++.h>
using namespace std;

const int INF=1e6;

vector<vector<int>> adj;
int n;

void warshall()
{
	int i,j,k;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(adj[i][k]+adj[k][j]<adj[i][j])
			adj[i][j]=adj[i][k]+adj[k][j];
		}
	}
}

void solve()
{
    int i,e,k;
    cin>>n>>k;
    adj=vector<vector<int>> (n,vector<int> (n,INF));
    vector<int> ware(k);
    for(i=0;i<k;i++)
    cin>>ware[i];
    cin>>e;
    while(e--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u][v]=w;
        adj[v][u]=w;
    }
    warshall();
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