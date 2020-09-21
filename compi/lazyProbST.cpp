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

int lazy[1000]={0};

void buildTree(int a[],int s,int e,int tree[],int ind)   // O(N)
{
    if(s==e)
    {
        tree[ind]=a[s];
        return;
    }
    int mid=(s+e)/2;
    buildTree(a,s,mid,tree,2*ind);
    buildTree(a,mid+1,e,tree,2*ind+1);
    tree[ind]=min(tree[2*ind],tree[2*ind+1]);
}

int minQuery(int s,int e,int qs,int qe,int tree[],int ind)    // O(log N)
{
    // First Step is to resolve the lazy value
    if(lazy[ind]!=0)
    {
        tree[ind]+=lazy[ind];
        if(s!=e)                // Not a leaf Node
        {
            lazy[2*ind]+=lazy[ind];
            lazy[2*ind+1]+=lazy[ind];
        }
        lazy[ind]=0;
    }

    if(s>=qs and e<=qe)   // Complete Overlap
        return tree[ind];

    if(qe<s or qs>e)      // No Overlap 
        return INF;

    // Partial Overlap - Call both sides
    int mid=(s+e)/2;
    int lans=minQuery(s,mid,qs,qe,tree,2*ind);
    int rans=minQuery(mid+1,e,qs,qe,tree,2*ind+1);
    return min(lans,rans);
}

// To update a node we paas l=r=i (for ith node) which takes O(log N) time

void updateRange(int s,int e,int l,int r,int inc,int tree[],int ind) // O(N), 
{
    // First Step is to resolve the lazy value
    if(lazy[ind]!=0)
    {
        tree[ind]+=lazy[ind];
        if(s!=e)                // Not a leaf Node
        {
            lazy[2*ind]+=lazy[ind];
            lazy[2*ind+1]+=lazy[ind];
        }
        lazy[ind]=0;
    }

    if(r<s or l>e)       // Out of Bound, No Overlap
        return;

    if(s>=l and e<=r)    // Complete Overlap - Beech raste me return karna hai
    {
        tree[ind]+=inc;
        if(s!=e)
        {
            lazy[2*ind]+=inc;
            lazy[2*ind+1]+=inc;
        }
        return;
    }

    // Partial Overlap - Call Both Sides
    int mid=(s+e)/2;
    updateRange(s,mid,l,r,inc,tree,2*ind);
    updateRange(mid+1,e,l,r,inc,tree,2*ind+1);
    tree[ind]=min(tree[2*ind],tree[2*ind]+1);
}

void solve()
{
	int i,n;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    int tree[4*n+1];
    buildTree(a,0,n-1,tree,1);
    //updateRange(0,n-1,1,3,10,tree,1);
    int q; // Number of queries
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<minQuery(0,n-1,l,r,tree,1)<<endl;
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