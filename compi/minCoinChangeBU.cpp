#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define ff first
#define ss second
#define mp make_pair
const int INF = 1e9;
const int MOD = 1e9 + 7;

void solve()
{
	int i,m,n;
    cin>>n; // note for which change is reqd
    cin>>m; // number of coins given
    vector<int> coins(m);
    for(i=0;i<m;i++)
    cin>>coins[i];
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++)
    {
        int ans=INF;
        for(int j=0;j<m;j++)
            if(i>=coins[j])
                ans=min(ans,dp[i-coins[j]]+1);
        dp[i]=ans;
    }
    cout<<dp[n]<<endl;
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