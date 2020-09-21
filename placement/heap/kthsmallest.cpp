#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
    int sz;
    vector<int> h;

    public:

    void heapify(int i)
    {
        int largest=i;
        int l=2*i+1;
        int r=2*i+2;
        if(l<sz and h[l]>h[largest])
            largest=l;
        if(r<sz and h[r]>h[largest])
            largest=r;
        if(largest!=i)
        {
            swap(h[i],h[largest]);
            heapify(largest);
        }
    }

    MaxHeap(vector<int> a,int k)
    {
        sz=k;
        h=a;
        for(int i=(sz-2)/2;i>=0;i--)
            heapify(i);
    }

    int getMax()
    {
        return h[0];
    }

    void replaceMax(int x)
    {
        h[0]=x;
        heapify(0);
    }
};

int kthSmallest(vector<int> a,int k)
{
    int i,n=a.size();
    MaxHeap m(a,k);
    for(i=k;i<n;i++)
    {
        if(a[i]<m.getMax())
        m.replaceMax(a[i]);
    }
    return m.getMax();
}

void solve()
{
    int i,n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<kthSmallest(a,k)<<endl;
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