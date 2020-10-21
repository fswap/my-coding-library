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

    void update(int i,int val)
    {
        while(i<=N)
        {
            BIT[i]+=val;
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

void convert(vector<int>& a)
{
    int i,n=a.size();
    vector<pair<int,int>> temp(n);
    for(i=0;i<n;i++)
    {
        temp[i].first=a[i];
        temp[i].second=i;
    }
    sort(temp.begin(),temp.end());
    for(i=0;i<n;i++)
    a[temp[i].second]=i+1;
}

void helper(vector<int> a)
{
    int i,n=a.size(),ans=INT_MIN;
    convert(a);
    FenwickTree ft;
    ft.init(n);
    vector<int> smallerRight(n),greaterLeft(n);
    for(i=n-1;i>=0;i--)
    {
        smallerRight[i]=ft.query(a[i]-1);
        ft.update(a[i],1);
    }
    ft.init(n);
    for(i=0;i<n;i++)
    {
        greaterLeft[i]=i-ft.query(a[i]);
        ft.update(a[i],1);
    }
    for(i=0;i<n;i++)
    ans=max(ans,abs(smallerRight[i]-greaterLeft[i]));
    cout<<ans<<endl;
}

void solve()
{
    int i,n;
    cin>>n;
    vector<int> a(n);
    for(i=0;i<n;i++)
    cin>>a[i];
    helper(a);
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