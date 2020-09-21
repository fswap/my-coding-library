#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define vec(x) vector<x>
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define mkp make_pair
#define vii vector<pair<int,int>>
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
{int res=1;while(b>0){if(b&1)res=((res%m)*(a%m))%m;
a=((a%m)*(a%m))%m;b>>=1;}return res;}
int dir[]={-1, 0, 1, 0, -1};
int dx[]={1,1,0,-1,-1,-1, 0, 1};
int dy[]={0,1,1, 1, 0,-1,-1,-1};

const int N = 1e6+1;

int s[N],x[N],y[N],f[N];

void solve()
{
	int i,n,k,itr=0,res=0;
	cin>>n>>k;
	int a,b,c,d;
	for(i=0;i<k;i++)
		cin>>s[i];
	cin>>a>>b>>c>>d;
	for(i=k;i<n;i++)
		s[i]=(a*s[i-2]+b*s[i-1]+c)%d;
	for(i=0;i<k;i++)
		cin>>x[i];
	cin>>a>>b>>c>>d;
	for(i=k;i<n;i++)
		x[i]=(a*x[i-2]+b*x[i-1]+c)%d;
	for(i=0;i<k;i++)
		cin>>y[i];
	cin>>a>>b>>c>>d;
	for(i=k;i<n;i++)
		y[i]=(a*y[i-2]+b*y[i-1]+c)%d;
	for(i=0;i<n;i++)
		itr+=(s[i]-x[i]);

	if(itr<0)
	{
		cout<<"-1"<<endl;
		return;
	}
	for(i=0;i<n;i++)
		f[i]=x[i];
	for(i=0;i<n;i++)
	{
		if(s[i]>x[i])
		{
			int cnt=min(y[i],s[i]-x[i]);
			if(itr>=cnt)
			{
				f[i]+=cnt;
				itr-=cnt;
			}
			else
			{
				f[i]+=itr;
				itr=0;
				break;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(itr>0)
		{
			int cnt=min(itr,x[i]+y[i]-f[i]);
			itr-=cnt;
			f[i]+=cnt;
		}
	}
	if(itr)
	{
		cout<<"-1"<<endl;
		return;
	}
	for(i=0;i<n;i++)
		res+=abs(f[i]-s[i]);
	cout<<res/2<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    t=1;
    cin>>t;
    int cnt=1;
    while(t--)
    {
        cout<<"Case #"<<cnt<<": ";
        solve();
        cnt++;
    }
}