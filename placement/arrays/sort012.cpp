#include<bits/stdc++.h>
using namespace std;

void helper(int a[],int n)
{
    int l=0,m=0,h=n-1;
    while(m<=h)
    {
        if(a[m]==0)
        swap(a[l++],a[m++]);
        else if(a[m]==1)
        m++;
        else
        swap(a[m],a[h--]);
    }
}

void solve()
{
    int i,n;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    helper(a,n);
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    int t=1;
    cin>>t;
    while(t--)
        solve();
}