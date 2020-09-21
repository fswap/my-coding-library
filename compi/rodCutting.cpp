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

vi price;
int dp[1000];

int helper(int n)
{
	if(n==0)
	return 0;
	if(dp[n]!=-1)
	return dp[n];
	int ans=0;
	for(int i=1;i<=n;i++)
	ans=max(ans,price[i]+helper(n-i));
	return dp[n]=ans;
}

void solve()
{
	int i,n;
	cin>>n;
	price=vi (n+1);
	for(i=1;i<=n;i++)
	cin>>price[i];
	mem(dp,-1);
	cout<<helper(n)<<endl;
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