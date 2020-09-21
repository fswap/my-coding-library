#include <bits/stdc++.h>
using namespace std;

vector<int> NSL(vector<int> a)
{
    int i,n=a.size();
    stack<int> st;
    vector<int> nsl(n);
    for(i=0;i<n;i++)
    {
        while(!st.empty() and a[st.top()]>=a[i])
            st.pop();
        if(st.empty())
            nsl[i]=-1; // assuming -1th index is of 0 height
        else
            nsl[i]=st.top();
        st.push(i);
    }
    return nsl;
}

vector<int> NSR(vector<int> a)
{
    int i,n=a.size();
    stack<int> st;
    vector<int> nsr(n);
    for(i=n-1;i>=0;i--)
    {
        while(!st.empty() and a[st.top()]>=a[i])
            st.pop();
        if(st.empty())
            nsr[i]=7; // assuming 7th index is of 0 height
        else
            nsr[i]=st.top();
        st.push(i);
    }
    return nsr;
}

int maxAreaHist(vector<int> a)
{
    int i,n=a.size(),ans=INT_MIN;
    vector<int> nsl=NSL(a);
    vector<int> nsr=NSR(a);
    for(i=0;i<n;i++)
        ans=max(ans,(nsr[i]-nsl[i]-1)*a[i]);
    return ans;
}

void solve()
{
    int i,j,n;
    cin>>n;
    vector<int> a(n);
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<maxAreaHist(a)<<endl;
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