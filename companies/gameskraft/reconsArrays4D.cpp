#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

int dp[51][101][51][51];

int solve(int n,int m,int cost,int last)
{
    if(n==0)
    {
        if(cost==0)
            return 1;
        return 0;
    }
    if(dp[n][m][cost][last]!=-1)
        return dp[n][m][cost][last];
    long long val=0;
    for(int i=last+1;i<=m;i++)
    {
        val+=solve(n-1,m,cost-1,i);
        val%=MOD;
    }
    val+=last*1ll*solve(n-1,m,cost,last);
    val%=MOD;
    return dp[n][m][cost][last]=val;
}

vector<int> arraysCount(vector<int> len,vector<int> mx,vector<int> cost)
{
    vector<int> ans;
    memset(dp,-1,sizeof dp);
    int i,j,n=len.size();
    for(i=0;i<n;i++)
    {
        long long val=0;
        for(j=1;j<=mx[i];j++)
        {
            val+=solve(len[i]-1,mx[i],cost[i],j);
            val%=MOD;
        }
        ans.push_back(val);
    }
    return ans;
}

void solve()
{
    int i,n;
    cin>>n;
    vector<int> len(n),mx(n),cost(n);
    for(i=0;i<n;i++)
    cin>>len[i];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>mx[i];
    cin>>n;
    for(i=0;i<n;i++)
    cin>>cost[i];
    vector<int> ans=arraysCount(len,mx,cost);
    for(i=0;i<n;i++)
    cout<<ans[i]<<endl;
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