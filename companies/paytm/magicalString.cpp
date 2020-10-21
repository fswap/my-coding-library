#include <bits/stdc++.h>
using namespace std;

unordered_map<string,bool> mp;

bool isPalin(string s)
{
    int i=0,j=s.size()-1;
    while(i<j)
    {
        if(s[i]!=s[j])
            return false;
        i++;j--;
    }
    return true;
}

int count(string s)
{
    int len,i,j,n=s.size(),cnt=0;
    for(len=1;len<=n;len++)
    {
        for(i=0;i<n-len+1;i++)
        {
            string str=s.substr(i,len);
            if(mp.count(str))
            {
                if(mp[str])
                    cnt++;
                continue;
            }
            if(isPalin(str))
            {
                cnt++;
                mp[str]=true;
            }
            else
            mp[str]=false;
        }
    }
    return cnt;
}

void solve()
{
    string s;
    cin>>s;
    cout<<count(s)<<endl;
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