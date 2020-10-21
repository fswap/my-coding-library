#include <bits/stdc++.h>
using namespace std;

int helper(int k,int a[],int n)
{
    if(n==0)
        return 0;
    int i,ans,mx=-1;
    for(i=0;i<n;i++)
    {
        int num=a[i],d,s=0;
        while(num>0)
        {
            d=num%10;
            if(d==k)
            s++;
            num=num/10;
        }
        if(s>mx)
        {
            mx=s;
            ans=a[i];
        }
    }
    if(mx==0)
        return -1;
    return ans;
}

void solve()
{
    int i,j,n,k;
    cin>>n>>k;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<helper(k,a,n)<<endl;
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