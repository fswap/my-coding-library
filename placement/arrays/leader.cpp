#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int i,n;
    cin>>n;
    int a[n];
    vector<int> ans;
    for(i=0;i<n;i++)
    cin>>a[i];
    int mx=a[n-1];
    ans.push_back(mx);
    for(i=n-2;i>=0;i--)
    {
        if(a[i]>=mx)
        {
            mx=a[i];
            ans.push_back(mx);
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto it:ans)
        cout<<it<<" ";
    cout<<endl;
}

int32_t main()
{
    int t=1;
    cin>>t;
    while(t--)
        solve();
}