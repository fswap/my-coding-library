#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int i,n;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    int l[n],r[n];
    l[0]=a[0];
    for(i=1;i<n;i++)
    l[i]=l[i-1]+a[i];
    r[n-1]=a[n-1];
    for(i=n-2;i>=0;i--)
    r[i]=r[i+1]+a[i];
    for(i=0;i<n;i++)
    {
        if(l[i-1]==r[i+1])
        {
            cout<<i+1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int32_t main()
{
    int t=1;
    cin>>t;
    while(t--)
        solve();
}