#include <bits/stdc++.h>
using namespace std;

#define endl " \n"
#define int long long
#define vec(x) vector<x>
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define matrix(x) vector<vector<x>>
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a, b, sizeof a)
#define setBits(n) __builtin_popcount(n)
#define ff first
#define ss second
#define mp make_pair
#define print(x) for(auto it:x) cout<<it<<" ";
#define dbg(x) cerr<<#x<<" :: "<<x<<endl;
#define dbg2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
const int INF = 1e9;
const int MOD = 1e9 + 7; 
int power(int a,int b,int m=MOD)
{int ans=1;while(b>0){if(b&1)ans=(ans*a)%m;a=(a*a)%m;b>>=1;}
return ans;}

void solve()
{
	int i,j,n,k;
	cin>>k>>n;
	vi a(n);
	for(i=0;i<n;i++)
	cin>>a[i];
	int dp[k+1][n+1];
	for(i=0;i<=k;i++)
	dp[i][0]=0;
	for(j=0;j<=n;j++)
	dp[0][j]=0;
	for(i=1;i<=k;i++)
	{
		for(j=1;j<n;j++)
		{
			int ans=INT_MIN;
			for(int m=0;m<j;m++)
			ans=max(ans,a[j]-a[m]+dp[i-1][m]); // ans is max so far
			dp[i][j]=max(dp[i][j-1],ans);	
		}
	}
	cout<<dp[k][n-1]<<endl;
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