#include <bits/stdc++.h>
using namespace std;

void sortKarr(vector<int>& a,int k)
{
    priority_queue<int,vector<int>,greater<int>> pq(a.begin(),a.begin()+k+1);
    int i,n=a.size(),idx=0;
    for(i=k+1;i<n;i++)
    {
        a[idx++]=pq.top();
        pq.pop();
        pq.push(a[i]);
    }
    while(!pq.empty())
    {
        a[idx++]=pq.top();
        pq.pop();
    }
}

void solve()
{
    int i,n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(i=0;i<n;i++)
    cin>>a[i];
    sortKarr(a,k);
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
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