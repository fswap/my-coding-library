#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define vec(x) vector<x>
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define matrix(x) vector<vector<x>>
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a, b, sizeof a)
#define setBits(n) __builtin_popcountll(n)
#define prec(n) fixed<<setprecision(n)
#define ff first
#define ss second
#define print(x) for(auto it:x) cout<<it<<" ";
#define dbg(x) cerr<<#x<<" :: "<<x<<endl;
#define dbg2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
const int INF = 1e9;
const int MOD = 1e9 + 7; 
const double pi = acos(-1);
int power(int a,int b,int m=MOD)
{int ans=1;while(b>0){if(b&1)ans=(ans*a)%m;a=(a*a)%m;b>>=1;}
return ans;}
int dir[]={-1, 0, 1, 0, -1};
int dx[]={1,1,0,-1,-1,-1, 0, 1};
int dy[]={0,1,1, 1, 0,-1,-1,-1};

const int N = 1e5+1;

void lcs(string s1,string s2)
{
    int i,j,m=s1.size(),n=s2.size();
    int dp[m+1][n+1];
    for(i=0;i<=m;i++)
    for(j=0;j<=n;j++)
    {
        if(i==0 or j==0)
        dp[i][j]=0;
        else if(s1[i-1]==s2[j-1])
        dp[i][j]=1+dp[i-1][j-1];
        else
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
	int ind=dp[m][n];
	char s[ind+1];
	s[ind]='\0';
	i=m,j=n;
	while(i>0 and j>0)
	{
		if(s1[i-1]==s2[j-1])
		{
			s[ind-1]=s1[i-1];
			ind--;i--;j--;
		}
		else if(dp[i-1][j]>dp[i][j-1])
		i--;
		else
		j--;
	}
	cout<<s<<endl;
}

void solve()
{
	string s1,s2;
	cin>>s1>>s2;
    lcs(s1,s2);
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