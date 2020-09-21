#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    vector<int> a;
    int capacity;
    int sz;

    public:

    MinHeap(int cap)
    {
        a=vector<int> (cap);
        capacity=cap;
        sz=0;
    }

    int parent(int i)
    {
        return (i-1)/2;
    }

    int left(int i)
    {
        return 2*i+1;
    }

    int right(int i)
    {
        return 2*i+2;
    }

    void insertKey(int k)
    {
        if(sz==capacity)
            return;
        sz++;
        int i=sz-1;
        a[i]=k;
        while(i!=0 and a[i]<a[parent(i)])
        {
            swap(a[i],a[parent(i)]);
            i=parent(i);
        }
    }

    void heapify(int i)
    {
        int smallest=i;
        int l=left(i);
        int r=right(i);

        if(l<sz and a[l]<a[smallest])
            smallest=l;
        if(r<sz and a[r]<a[smallest])
            smallest=r;
        if(smallest!=i)
        {
            swap(a[i],a[smallest]);
            heapify(smallest);
        }
    }

    int getMin()
    {
        if(sz<=0)
            return INT_MAX;
        return a[0];
    }

    int extractMin()
    {
        if(sz<=0)
            return INT_MAX;
        if(sz==1)
        {
            sz--;
            return a[0];
        }
        int root=a[0];
        swap(a[0],a[sz-1]);
        sz--;
        heapify(0);
        return root;
    }

    void decreaseKey(int i,int k)
    {
        a[i]=k;
        while(i!=0 and a[i]<a[parent(i)])
        {
            swap(a[i],a[parent(i)]);
            i=parent(i);
        }
    }

    void deleteKey(int i)
    {
        decreaseKey(i,INT_MIN);
        extractMin();
    }
};

void solve()
{
    MinHeap h(11);
    h.insertKey(3); 
    h.insertKey(2); 
    h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45); 
    cout<<h.extractMin()<<" "; 
    cout<<h.getMin()<<" "; 
    h.decreaseKey(2, 1); 
    cout<<h.getMin();
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