#include <bits/stdc++.h>
using namespace std;
 
#define endl "\n"
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define matrix vector<vector<int>>
#define ff first
#define ss second
#define mp make_pair
const int INF = 1e9;
const int MOD = 1e9 + 7;
 
int BIT[10000005];
int mx;
 
void update(int i,int inc)
{
    while(i<=mx)
    {
        BIT[i]+=inc;   // for rangeMax here BIT[i]=max(BIT[i],val), where val is the new value
        i+=(i&(-i));
    }
}
 
int query(int i)
{
    int sum=0;
    while(i>0)
    {
        sum+=BIT[i];  // for rangeMax here ans=max(ans,BIT[i])
        i-=(i&(-i));
    }
    return sum;
}
 
void solve()
{
	ll n,i,ans=0;
    memset(BIT,0,sizeof BIT);
    cin>>n;
    int a[n];
    mx=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    for(i=n-1;i>=0;i--)
    {
        ans+=query(a[i]-1);
        update(a[i],1);
    }
    cout<<ans<<endl;
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
