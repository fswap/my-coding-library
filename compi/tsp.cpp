#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
const int INF = 1e9;
const int MOD = 1e9 + 7;

vector<vector<int>> adj(10,vector<int> (10));
vector<vector<int>> dp(1024,vector<int> (10,-1)); // dp[(1<<n)][n], here n=max(n) for all cases

int tsp(int n,int mask,int pos)
{
    if(mask==(1<<n)-1)
        return adj[pos][0];
    if(dp[mask][pos]!=-1)
        return dp[mask][pos];
    int ans=INF;
    for(int city=0;city<n;city++)
    {
        if(city!=pos && (mask & (1<<city))==0)
        ans=min(ans,adj[pos][city]+tsp(n,mask|(1<<city),city));
    }
    return dp[mask][pos]=ans;
}

void solve()
{
	int i,j,n;
    cin>>n;
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        cin>>adj[i][j];  // adjacency matrix

    cout<<"Min Wt. Hamiltonian cycle cost: "<<tsp(n,1,0);
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