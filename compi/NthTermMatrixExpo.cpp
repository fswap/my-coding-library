#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define vec(x) vector<x>
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define vvi vector<vector<int>>
#define umpii unordered_map<int,int>
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
int n;

vvi multiply(vvi A,vvi B)
{
	int i,j,k;
	vvi C(n+1,vi (n+1,0));
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	for(k=1;k<=n;k++)
	{
		C[i][j]=(C[i][j]+(A[i][k]*B[k][j])%MOD)%MOD;
	}
	return C;
}

vvi matrixExpo(vvi A,int p)
{
	if(p==1)
	return A;
	else if(p&1)
	return multiply(A,matrixExpo(A,p-1));
	else
	{
		vvi X=matrixExpo(A,p/2);
		return multiply(X,X);
	}
}

void solve()
{
	int i,j,x,ans=0;
	cin>>n;
	vi b(n+1),c(n+1);
	for(i=1;i<=n;i++)
	cin>>b[i];
	for(i=1;i<=n;i++)
	cin>>c[i];
	cin>>x;
	if(x<=n)
	{
		cout<<b[x]<<endl;
		return;
	}
	vvi T(n+1,vi (n+1));
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i<n)
			T[i][j]=(j==i+1);
			else
			T[i][j]=c[n-j+1];
		}
	}
	T=matrixExpo(T,x-1);
	for(i=1;i<=n;i++)
	ans=(ans+(T[1][i]*b[i])%MOD)%MOD;
	cout<<ans<<endl;
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