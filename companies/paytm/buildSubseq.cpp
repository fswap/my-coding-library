#include <bits/stdc++.h>
using namespace std;

void buildSubseq(string s)
{
    int i,j,n=s.size(),lim=(1<<n),t=0;
    string ans[lim-1];
    for(i=0;i<lim;i++)
    {
        string str="";
        for(j=0;j<n;j++)
        {
            if(i&(1<<j))
            str+=s[j];
        }
        if(str.size()>0)
        ans[t++]=str;
    }
    sort(ans,ans+lim-1);
    for(i=0;i<lim-1;i++)
    cout<<ans[i]<<endl;
}

void solve()
{
    string s;
    cin>>s;
    int i,n=s.size(),lim=(1<<n);
    buildSubseq(s);
    // for(i=0;i<lim;i++)
    // cout<<ans[i]<<endl;
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