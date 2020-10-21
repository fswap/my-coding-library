#include <bits/stdc++.h>
using namespace std;

int maxSubseqLength(int n,int k,vector<int> a)
{
    unordered_map<int,int> mp;
    int i,mx=1;
    for(i=0;i<n;i++)
    {
        int len=mp[a[i]^k]+1;
        mp[a[i]]=len;
        mx=max(mx,len);
    }
    return mx;
}

void solve()
{
    int i,j,n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<maxSubseqLength(n,k,a)<<endl;
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