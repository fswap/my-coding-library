#include <bits/stdc++.h>
using namespace std;

vector<int> stockspan(vector<int> a) // same as NGL, can also be done without stack
{
    int i,n=a.size();
    stack<int> st;
    vector<int> ans(n);
    for(i=0;i<n;i++)
    {
        while(!st.empty() and a[st.top()]<=a[i])
            st.pop();
        if(st.empty())
            ans[i]=i+1;
        else
            ans[i]=i-st.top();
        st.push(i);
    }
    return ans;
}

void solve()
{
    int i,j,n;
    cin>>n;
    vector<int> a(n);
    for(i=0;i<n;i++)
    cin>>a[i];
    vector<int> ans=stockspan(a);
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