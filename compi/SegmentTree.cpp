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

struct SegmentTree
{
    int N;
    vi tree;

    void init(int n)
    {
        N=n;
        tree.resize(4*n+1,0);
    }

    void update(int s,int e,int l,int r,int val,int ind)
    {
        if(r<s or l>e)
        return;
        if(s==e)
        {
            tree[ind]+=val;
            return;
        }
        int m=(s+e)/2;
        update(s,m,l,r,val,2*ind);
        update(m+1,e,l,r,val,2*ind+1);
        tree[ind]=min(tree[2*ind],tree[2*ind+1]);
    }

    int query(int s,int e,int l,int r,int ind)
    {
        if(r<s or l>e)
        return INF;
        if(s>=l and e<=r)
        return tree[ind];
        int m=(s+e)/2;
        return min(query(s,m,l,r,2*ind),query(m+1,e,l,r,2*ind+1));
    }
};

void solve()
{
	int i,n,q,x;
	cin>>n>>q;
    SegmentTree st;
    st.init(n);
    for(i=0;i<n;i++)
    {
        cin>>x;
        st.update(0,n-1,i,i,x,1);
    }
    while(q--)
    {
        int type,l,r;
        cin>>type;
        if(type==1)
        {
            cin>>l>>r;
            cout<<st.query(0,n-1,l,r,1)<<endl;
        }
        else
        {
            int val;
            cin>>l>>r>>val;
            st.update(0,n-1,l,r,val,1);
        }
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