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

void solve()
{
	int n;
    cin>>n;
    vector<int> dp(n+1);
    dp[1]=0;
    for(int i=2;i<=n;i++)
    {
        int ans=dp[i-1]+1;
        if(i%3==0)
        ans=min(ans,dp[i/3]+1);
        if(i%2==0)
        ans=min(ans,dp[i/2]+1);
        dp[i]=ans;
    }
    cout<<dp[n]<<endl;
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