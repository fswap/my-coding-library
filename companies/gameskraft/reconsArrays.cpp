#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;

long dp[52][102][52];
int pref[52][102][52];

int count(int n,int m,int cost)
{
    int i,j,k;
    memset(dp,0,sizeof(dp));
    memset(pref,0,sizeof(pref));
    for(j=1;j<=m;j++)
    {
        dp[1][j][0]=1;
        pref[1][j][0]=j;
    }
    for(i=2;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            for(k=0;k<=cost;k++)
            {
                dp[i][j][k]=(j*dp[i-1][j][k])%MOD;
                dp[i][j][k]+=pref[i-1][j-1][k-1];
                dp[i][j][k]%=MOD;
                pref[i][j][k]=(pref[i][j-1][k]+dp[i][j][k])%MOD;
            }
        }
    }
    return pref[n][m][cost];
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
    for(i=0;i<n;i++)
    cout<<count(len[i],mx[i],cost[i])<<endl;
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