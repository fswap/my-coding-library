#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> a,int n,int m)
{
    sort(a.begin(),a.end());
    int l=a[0],r=a[n-1];
    int i,mx=-1;
    while(l<=r)
    {
        int ans=0;
        int mid=l+(r-l)/2;
        for(i=0;i<n;i++)
        {
            ans+=(a[i]/mid);
            if(a[i]%mid)
                ans++;
        }
        if(ans<=m)
        {
            mx=mid;
            r=mid-1;
        }
        else
        l=mid+1;
    }
    return mx;
}

void solve()
{
    int i,j,n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<helper(a,n,m)<<endl;
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