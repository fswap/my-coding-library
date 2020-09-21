#include<bits/stdc++.h>
using namespace std;

int maxsumsubarr(vector<int> a)
{
    int i,curr=a[0],tot=a[0],n=a.size();
    for(i=1;i<n;i++)
    {
        curr=max(a[i],curr+a[i]);
        tot=max(tot,curr);
    }
    return tot;
}

void solve()
{
    int i,n;
    cin>>n;
    vector<int> a(n);
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<maxsumsubarr(a)<<endl;
}

int main()
{
    int t=1;
    cin>>t;
    while(t--)
        solve();
}