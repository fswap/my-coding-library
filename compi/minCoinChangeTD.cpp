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

vector<int> coins(1000),dp(1000,-1);

int coinChange(int n,int m)
{
    if(n==0)
        return 0;
    if(dp[n]!=-1)
        return dp[n];
    int ans=INF;
    for(int i=0;i<m;i++)
    {
        if(n>=coins[i])
        ans=min(ans,coinChange(n-coins[i],m)+1);
    }
    return dp[n]=ans;
}

void solve()
{
	int i,m,n;
    cin>>n; // note for which change is reqd
    cin>>m; // number of coins given
    for(i=0;i<m;i++)
    cin>>coins[i];
    cout<<coinChange(n,m)<<endl;
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