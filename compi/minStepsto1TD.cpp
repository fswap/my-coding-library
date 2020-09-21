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

vector<int> dp(100,-1);

int minSteps(int n)
{
    if(n==1)
        return 0;
    if(dp[n]!=-1)
        return dp[n];
    int op1,op2,op3;
    op1=op2=op3=INF;
    if(n%3==0)
        op1=minSteps(n/3)+1;
    if(n%2==0)
        op2=minSteps(n/2)+1;
    op3=minSteps(n-1)+1;
    int ans=min(op1,min(op2,op3));
    return dp[n]=ans;
}

void solve()
{
	int n;
    cin>>n;
    cout<<minSteps(n)<<endl;
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