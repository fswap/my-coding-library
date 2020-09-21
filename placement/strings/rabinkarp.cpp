#include <bits/stdc++.h>
using namespace std;

const int MOD=101; // prime number

void rabinKarp(string str,string pat)
{
    int i,j,n=str.size(),m=pat.size(),h=1,p=0,s=0,d=256;
    for(i=0;i<m-1;i++)
        h=(h*d)%MOD;
    for(i=0;i<m;i++)
    {
        p=(p*d+pat[i])%MOD;
        s=(s*d+str[i])%MOD;
    }
    for(i=0;i<=n-m;i++)
    {
        if(s==p)
        {
            for(j=0;j<m;j++)
            {
                if(str[i+j]!=pat[j])
                break;
            }
            if(j==m)
            cout<<"Pattern found at "<<i<<endl;
        }
        if(i<n-m)
        {
            s=(d*(s-str[i]*h)+str[i+m])%MOD;
            if(s<0)
            s+=MOD;
        }
    }
}

void solve()
{
    string str,pat;
    getline(cin,str);
    getline(cin,pat);
    rabinKarp(str,pat);
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