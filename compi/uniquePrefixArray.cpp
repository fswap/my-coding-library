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
	bool isLeaf;
	int cnt;
	unordered_map<char,Trie*> mp;
};

Trie* newNode()
{
	Trie *n=new Trie();
	n->cnt=1;
	n->isLeaf=false;
}

void insert(Trie* root,string s)
{
	Trie *curr=root;
	for(char x:s)
	{
		if(!curr->mp.count(x))
		curr->mp[x]=newNode();
		else
		(curr->mp[x]->cnt)++;
		curr=curr->mp[x];
	}
	curr->isLeaf=true;
}

void findPrefixes(Trie* root,char prefix[],int ind)
{
	if(root==NULL)
		return;
	if(root->cnt==1)
	{
		prefix[ind]='\0';
		cout<<prefix<<" ";
		return;
	}
	for(auto it:root->mp)
	{
		prefix[ind]=it.ff;
		findPrefixes(root->mp[it.ff],prefix,ind+1);
	}
}

void solve()
{
	int i,n;cin>>n;
	string s;
	Trie* root=newNode();
	root->cnt=0;
	for(i=0;i<n;i++)
	{
		cin>>s;
		insert(root,s);
	}
	char prefix[1000];
	findPrefixes(root,prefix,0);
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