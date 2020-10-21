#include <bits/stdc++.h>
using namespace std;

const int INF=1e6;

vector<vector<int>> adj;
vector<int> ware;
int n,num;

void warshall()
{
	int i,j,k,ans=INF;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(adj[i][k]+adj[k][j]<adj[i][j])
			adj[i][j]=adj[i][k]+adj[k][j];
		}
	}
    for(i=0;i<ware.size();i++)
    {
        for(j=i+1;j<ware.size();j++)
        {
            ans=min(ans,adj[ware[i]][ware[j]]);
        }
    }
    cout<<ans<<endl;
}

void solve()
{
    int i,e,num,j;
    cin>>n>>num;
    adj=vector<vector<int>> (n,vector<int> (n,INF));
    for(i=0;i<n;i++)
    adj[i][i]=0;
    ware=vector<int> (num);
    for(i=0;i<num;i++)
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