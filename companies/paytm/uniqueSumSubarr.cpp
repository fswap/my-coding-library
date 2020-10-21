#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> a)
{
    int i=0,j=1,n=a.size();
    unordered_set<int> st;
    st.insert(a[0]);
    int sum=a[0];
    int mx=sum;
    while(i<n-1 and j<n)
    {
        if(!st.count(a[j]))
        {
            sum+=a[j];
            mx=max(mx,sum);
            st.insert(a[j++]);
        }
        else
        {
            sum-=a[i];
            st.erase(a[i++]);
        }
    }
    return mx;
}

void solve()
{
    int i,j,n,m;
    cin>>n;
    vector<int> a(n);
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<helper(a)<<endl;
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