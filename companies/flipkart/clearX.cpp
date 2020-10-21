#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> start,vector<int> end)
{
    int i,n=start.size(),ans=0;
    vector<pair<int,int>> a(n);
    for(i=0;i<n;i++)
    {
        a[i].first=start[i];
        a[i].second=end[i];
    }
    sort(a.begin(),a.end());
    pair<int,int> temp=a[0];
    for(auto p:a)
    {
        if(p.first<=temp.second)
        temp.second=max(p.second,temp.second);
        else
        {
            ans++;
            temp=p;
        }
    }
    return ans;
}

void solve()
{
    int i,n;
    cin>>n;
    vector<int> start(n),end(n);
    for(i=0;i<n;i++)
    cin>>start[i];
    for(i=0;i<n;i++)
    cin>>end[i];
    cout<<helper(start,end)<<endl;
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