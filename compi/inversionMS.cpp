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
#define setBits(n) __builtin_popcount(n)
#define ff first
#define ss second
#define mp make_pair
#define print(x) for(auto it:x) cout<<it<<" ";
#define dbg(x) cerr<<#x<<" :: "<<x<<endl;
#define dbg2(x,y) cerr<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
const int INF = 1e9;
const int MOD = 1e9 + 7; 
int power(int a,int b,int m=MOD)
{int ans=1;while(b>0){if(b&1)ans=(ans*a)%m;a=(a*a)%m;b>>=1;}
return ans;}

int merge(int a[],int s,int m,int e)
{
    int temp[e-s+1],i=s,j=m+1,k=0,cnt=0;
    while(i<=m and j<=e)
    {
        if(a[i]<=a[j])
        temp[k++]=a[i++];
        else
        {
            temp[k++]=a[j++];
            cnt+=m-i+1;
        }
    }
    while(i<=m)
    temp[k++]=a[i++];
    while(j<=e)
    temp[k++]=a[j++];

    for(i=0;i<k;i++)
    a[i+s]=temp[i];

    return cnt;
}

int mergeSort(int a[],int s,int e)
{
    int cnt=0;
    if(s<e)
    {
        int m=s+(e-s)/2;
        cnt+=mergeSort(a,s,m);
        cnt+=mergeSort(a,m+1,e);
        cnt+=merge(a,s,m,e);
    }
	return cnt;
}

void solve()
{
    int n,i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<mergeSort(a,0,n-1)<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	//t=1;
	cin>>t;
	while(t--)
		solve();
}