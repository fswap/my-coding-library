#include <bits/stdc++.h>
using namespace std;

struct FenwickTree
{
    int N;
    vector<int> BIT;

    void init(int n)
    {
        N=n;
        BIT.assign(n+1,0);
    }

    void update(int i,int inc)
    {
        while(i<=N)
        {
            BIT[i]+=inc;
            i+=(i&(-i));
        }
    }

    int query(int i)
    {
        int ans=0;
        while(i>0)
        {
            ans+=BIT[i];
            i-=(i&(-i));
        }
        return ans;
    }
};

long minimumOperations(vector<int> a)
{
    int i,n=a.size();
    long ans=0;
    int mx=*(max_element(a.begin(),a.end()));
    FenwickTree ft;
    ft.init(mx);
    vector<int> smallerRight(n),greaterLeft(n);
    for(i=n-1;i>=0;i--)
    {
        smallerRight[i]=ft.query(a[i]-1);
        ft.update(a[i],1);
    }
    ft.init(mx);
    for(i=0;i<n;i++)
    {
        greaterLeft[i]=i-ft.query(a[i]);
        ft.update(a[i],1);
    }
    for(i=0;i<n;i++)
    ans+=2*1ll*min(smallerRight[i],greaterLeft[i])+1;
    return ans;
}

void solve()
{
    int i,j,n,m;
    cin>>n;
    vector<int> a(n);
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<minimumOperations(a)<<endl;
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