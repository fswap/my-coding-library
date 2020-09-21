#include <bits/stdc++.h>
using namespace std;

#define endl " \n"
#define ll long long
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
	string s,p;
	cin>>s>>p;
	int m=s.size(),n=p.size(),i,j;
	bool dp[m+1][n+1];
	mem(dp,false);
	dp[0][0]=true;
	for(j=1;j<=n;j++)
	if(p[j-1]=='*')
	dp[0][j]=dp[0][j-1];
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(p[j-1]=='*')
			dp[i][j]=dp[i-1][j] or dp[i][j-1];
			else if(p[j-1]=='?' or (s[i-1]==p[j-1]))
			dp[i][j]=dp[i-1][j-1];
			else
			dp[i][j]=false;
		}
	}
	if(dp[m][n])
	cout<<"MATCHED"<<endl;
	else
	cout<<"NOT MATCHED"<<endl;
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