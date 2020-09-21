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

const int N = 1e2+1;
int a[N][N];
int n;

int dijkstra()
{
	matrix(int) dis(n,vi(n,INF));
	set<pair<int,pii>> st;
	st.insert({0,{0,0}});
	dis[0][0]=a[0][0];
	while(!st.empty())
	{
		pii p=st.begin()->ss;
		st.erase(st.begin());
		int x=p.ff,y=p.ss;
		for(int i=0;i<4;i++)
		{
			int xx=x+dir[i],yy=y+dir[i+1];
			if(xx>=0 and yy>=0 and xx<n and yy<n and dis[x][y]+a[xx][yy]<dis[xx][yy])
			{
				st.erase({dis[xx][yy],{xx,yy}});
				dis[xx][yy]=dis[x][y]+a[xx][yy];
				st.insert({dis[xx][yy],{xx,yy}});
			}
		}
	}
	return dis[n-1][n-1];
}

void solve()
{
	int i,j;
	cin>>n;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	cin>>a[i][j];
	cout<<dijkstra()<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	t=1;
	cin>>t;
	while(t--)
		solve();
}