#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    int sz;
    vector<int> h;
    public:
    MinHeap(vector<int> a,int n);
    void heapify(int i);
    int getMin()
    {
        return h[0];
    }
    void replaceMin(int x)
    {
        h[0]=x;
        heapify(0);
    }
    void printHeap()
    {
        for(int i=0;i<sz;i++)
        cout<<h[i]<<" ";
        cout<<endl;
    }
};

MinHeap::MinHeap(vector<int> a,int n)
{
    sz=n;
    h=a;
    for(int i=(sz-2)/2;i>=0;i--)
        heapify(i);
}

void MinHeap::heapify(int i)
{
    int smallest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<sz and h[l]<h[smallest])
        smallest=l;
    if(r<sz and h[r]<h[smallest])
        smallest=r;
    if(smallest!=i)
    {
        swap(h[i],h[smallest]);
        heapify(smallest);
    }
}
    
void firstKElements(vector<int> a,int k)
{
    MinHeap m(a,k);
    int i,n=a.size();
    for(i=k;i<n;i++)
    {
        if(a[i]>m.getMin())
        m.replaceMin(a[i]);
    }
    m.printHeap();
}

void solve()
{
    int i,n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(i=0;i<n;i++)
    cin>>a[i];
    firstKElements(a,k);
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