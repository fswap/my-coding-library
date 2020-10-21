#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    int i,q,len,k,n=s.size();
    cin>>q;
    while(q--)
    {
        unordered_map<string,int> mp;
        vector<pair<int,string>> v;
        cin>>len>>k;
        int f=0;
        for(i=0;i<n-len+1;i++)
        {
            string str=s.substr(i,len);
            v.push_back({i,str});
            mp[str]++;
        }
        for(auto p:v)
        {
            if(mp[p.second]==1)
            {
                k--;
                if(k==0)
                {
                    cout<<p.first+1<<endl;
                    f=1;
                    break;
                }
            }
        }
        if(f==0)
        cout<<-1<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    t=1;
    cin>>t;
    while(t--)
        solve();
}