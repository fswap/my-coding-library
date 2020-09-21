#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define matrix vector<vector<int>>
#define ff first
#define ss second
#define mp make_pair
const int INF = 1e9;
const int MOD = 1e9 + 7;

vi price(1000);
matrix dp(100,vi (100,-1));

int wines(int i,int j,int y)   // i is the left end and j is the right end, y is the year
{
    if(i>j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j]=max(wines(i+1,j,y+1),wines(i,j+1,y+1));
    return dp[i][j];
}

void solve()
{
	int i,n;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>price[i];
    cout<<wines(0,n-1,1)<<endl;
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