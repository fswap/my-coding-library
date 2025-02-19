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
#define ff first
#define ss second
#define print(x) for(auto it:x) cout<<it<<" ";
#define dbg(x) cerr<<#x<<" :: "<<x<<endl;
#define dbg2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
const int INF = 1e9;
const int MOD = 1e9 + 7; 
int power(int a,int b,int m=MOD)
{int ans=1;while(b>0){if(b&1)ans=(ans*a)%m;a=(a*a)%m;b>>=1;}
return ans;}
int dir[]={-1, 0, 1, 0, -1};
int dx[]={1,1,0,-1,-1,-1, 0, 1};
int dy[]={0,1,1, 1, 0,-1,-1,-1};

struct FenwickTree
{
    int N;
    vector<int> BIT;

    void init(int n)
    {
        N=n;
        BIT.assign(n+1,0);
    }

    void update(int i,int val)
    {
        while(i<=N)
        {
            BIT[i]+=val;   // for rangeMax here BIT[i]=max(BIT[i],val), where val is the new value
            i+=(i&(-i));
        }
    }

    int query(int i)
    {
        int ans=0;
        while(i>0)
        {
            ans+=BIT[i];  // for rangeMax here ans=max(ans,BIT[i])
            i-=(i&(-i));
        }
        return ans;
    }

    int find(int k) // lower bound in BIT array
    {
        int pos=0,sum=0;
        for(int i=log2(N);i>=0;i--)
        {
            if(pos+(1<<i)<N and sum+BIT[pos+(1<<i)]<k)
            {
                pos+=(1<<i);
                sum+=BIT[pos];
            }
        }
        return pos+1; // +1 because 'pos' will have position of largest value less than 'k'
    }

    int rsum(int l,int r)
    {
        return query(r)-query(l-1);
    }
};

void solve()
{
	int n,i,q,x;
    cin>>n>>q;
    FenwickTree bit;
    bit.init(n);
    for(i=1;i<=n;i++)
    {
        cin>>x;
        bit.update(i,x);
    }
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<bit.rsum(l,r)<<endl;
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