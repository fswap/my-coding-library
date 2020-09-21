#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int i,j,n;
    cin>>n;
    int a[n],d[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<n;i++)
    cin>>d[i];
    sort(a,a+n);sort(d,d+n);
    i=1,j=0;
    int ans=1,p=1;
    while(i<n and j<n)
    {
        if(a[i]<=d[j])
        {
            p++;
            i++;
            ans=max(ans,p);
        }
        else
        {
            p--;
            j++;
        }
    }
    cout<<ans<<endl;
}

int32_t main()
{
    int t=1;
    cin>>t;
    while(t--)
        solve();
}