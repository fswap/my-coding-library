#include <bits/stdc++.h>
using namespace std;

#define endl " \n"
#define ll long long
#define vec(x) vector<x>
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define matrix(x) vector<vector<x>>
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a, b, sizeof a)
#define setBits(n) __builtin_popcount(n)
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

struct Trie
{
	int val;
	Trie *child[2];
};

Trie* newNode()
{
	Trie *n=new Trie();
	n->val=0;
	n->child[0]=n->child[1]=NULL;
	return n;
}

void insert(Trie* root,int key)
{
	Trie *curr=root;
	for(int i=31;i>=0;i--)
	{
		int b=key & (1<<i);
		if(!curr->child[b])
		curr->child[b]=newNode();
		curr=curr->child[b];
	}
	curr->val=key;
}

int maxXor(Trie* root,int key)
{
	Trie *curr=root;
	for(int i=31;i>=0;i--)
	{
		int b=key & (1<<i);
		if(curr->child[1-b])
		curr=curr->child[1-b]; // for minimum first evaluate the same bits
		else
		curr=curr->child[b];
	}
	return key^curr->val; // curr->val gives the maximum XOR with given key
}

void solve()
{
	int i,n,ans=INT_MIN;
	cin>>n;
	vi a(n);
	for(i=0;i<n;i++)
	cin>>a[i];
	Trie *root=newNode();
	insert(root,a[0]);
	for(i=1;i<n;i++)
	{
		ans=max(ans,maxXor(root,a[i]));// use prefix xor to find max xor subarray
		insert(root,a[i]);
	}
	cout<<ans<<endl;
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