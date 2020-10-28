#include <bits/stdc++.h>
using namespace std;

int fib[50];

void precomp()
{
    fib[0]=1;
    fib[1]=2;
    for(int i=2;i<50;i++)
    fib[i]=fib[i-1]+fib[i-2];
}

void solve()
{
    int i,k;
    cin>>k;
    string ans="";
    for(i=40;i>=0;i--)
    {
        if(k>=fib[i])
        {
            k-=fib[i];
            ans+="1";
        }
        else if(ans.size())
        ans+="0";
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    t=1;
    precomp();
    cin>>t;
    while(t--)
        solve();
}