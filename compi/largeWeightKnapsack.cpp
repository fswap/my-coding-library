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

const int N = 1e3+1;
int val[N],wt[N];
int n,w;

int knapsack()
{
    int i,j,V=0;    // V is the maximum value possible
    for(i=0;i<n;i++)
    V+=val[i];
    vector<int> dp(V+1,INF); // the minimum total weight of items with total value exactly i
    dp[0]=0;
    for(i=0;i<n;i++)
    {
        for(j=V;j>=val[i];j--)
        dp[j]=min(dp[j],wt[i]+dp[j-val[i]]);
    }
    for(i=V;i>=0;i--)
        if(dp[i]<=w)
        return i;
    return 0;
}

void solve()
{
	int i;
	cin>>n>>w;
    for(i=0;i<n;i++)
    cin>>wt[i]>>val[i];
    cout<<knapsack()<<endl;
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