#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& a,int n,int i)
{
    int l=2*i+1;
    int r=2*i+2;
    int largest=i;

    if(l<n and a[l]>a[largest])
        largest=l;
    if(r<n and a[r]>a[largest])
        largest=r;
    if(largest!=i)
    {
        swap(a[largest],a[i]);
        heapify(a,n,largest);
    }
}

void heapsort(vector<int>& a)
{
    int i,n=a.size();
    for(i=(n-2)/2;i>=0;i--)
        heapify(a,n,i);
    for(i=n-1;i>=0;i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

void solve()
{
    int i,n;
    cin>>n;
    vector<int> a(n);
    for(i=0;i<n;i++)
    cin>>a[i];
    heapsort(a);
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