#include <bits/stdc++.h>
using namespace std;

vector<int> helper(vector<int> a,int k)
{
    int i,n=a.size();
    vector<int> ans;
    for(i=0;i<n;i++)
    {
        int j=i,cnt=k,val=0;
        if(a[i]>0)
        {
            while(cnt>0)
            {
                val+=a[(j+1)%n];
                j++;
                cnt--;
            }
        }
        else
        {
            while(cnt>0)
            {
                val+=a[(j+k)%n];
                j--;
                cnt--;
            }
        }
        ans.push_back(val);
    }
    return ans;
}

void solve()
{
    int i,n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(i=0;i<n;i++)
    cin>>a[i];
    vector<int> ans=helper(a,k);
    for(i=0;i<n;i++)
    cout<<ans[i]<<" ";
    cout<<endl;
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