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
#define ff first
#define ss second
#define mp make_pair
#define print(x) for(auto it:x) cout<<it<<" ";
#define dbg(x) cerr<<#x<<" :: "<<x<<endl;
#define dbg2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
const int INF = 1e9;
const int MOD = 1e9 + 7; 

#define MAXN 100000

int st[MAXN+1][25];
int LOG[MAXN+1];
int a[MAXN];

void comLog()
{
	LOG[1]=(int)0;
	for(int i=2;i<=MAXN;i++)
	LOG[i]=LOG[i/2]+1;
}

void precompute(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    st[i][0]=a[i];
    for(j=1;(1<<j)<=n;j++)
    {
        for(i=0;i+(1<<j)<=n;i++)
        st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
    }
}

void solve()
{
	int i,n,q;
    cin>>n;
    for(i=0;i<n;i++)
	cin>>a[i];
    precompute(n);
	comLog();
	cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        int j=LOG[r-l+1];
        cout<<min(st[l][j],st[r-(1<<j)+1][j])<<endl;
    }
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