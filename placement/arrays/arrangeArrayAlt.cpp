#include<bits/stdc++.h>
using namespace std;

#define int long long

void arrange(int a[],int n)
{
    int mx=n-1,mn=0,i;
    int maxele=a[mx]+1;
    for(i=0;i<n;i++)
    {
        if(i&1)
            a[i]+=(a[mn++]%maxele)*maxele;
        else
            a[i]+=(a[mx--]%maxele)*maxele;
    }
    for(i=0;i<n;i++)
    a[i]=a[i]/maxele;
}

void solve()
{
    int i,j,n;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    arrange(a,n);
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