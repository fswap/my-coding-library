#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define vec(x) vector<x>
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
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
{int ans=1;while(b>0){if(b&1)ans=(ans*a)%m;a=(a*a)%m;b>>=1;}
return ans;}
int dir[]={-1, 0, 1, 0, -1};
int dx[]={1,1,0,-1,-1,-1, 0, 1};
int dy[]={0,1,1, 1, 0,-1,-1,-1};

const int N = 5000000+1;

// N = p1^k1 * p2^k2 * p3^k3 .... pm^km

// Number of divisors 	=  		(k1 + 1)*(k2 + 1)*(k3 + 1)...(km + 1)
// Sum of divisors 		= 		SUM[ ( pi^(ki+1) - 1 ) / (pi - 1) ]
// Product of Divisors 	= 		power(N,Numer of divisors/2);

vec(bool) isPrime;
vi primes;

void initPrime(int MAXN)
{
	primes={};
	for(int i=2;i<=MAXN;i++)
	if(isPrime[i])
	primes.pb(i);
}
 
void sieve(int MAXN)
{
	isPrime.assign(MAXN+1,true);
	isPrime[0]=isPrime[1]=false;
	for(int i=2;i*i<=MAXN;i++)
	{
		if(isPrime[i])
		{
			for(int j=i*i;j<=MAXN;j+=i)
			isPrime[j]=false;
		}
	}
}

void precomp()
{
	sieve(28);
	initPrime(28);
}

void solve()
{
	int i,k;
	print(primes);
	cout<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	t=1;
	//cin>>t;
	precomp();
	while(t--)
		solve();
}