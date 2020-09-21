#include<bits/stdc++.h>
using namespace std;

void triplets(vector<int> a,int sum)
{
    int i,l,r,n=a.size();
    sort(a.begin(),a.end());
    for(i=0;i<n-2;i++)
    {
        l=i+1,r=n-1;
        while(l<r)
        {
            if(a[i]+a[l]+a[r]==sum)
            {
                cout<<1<<endl;
                return;
            }
            else if(a[i]+a[l]+a[r]<sum)
            l++;
            else
            r--;
        }
    }
    cout<<0<<endl;
}

void solve()
{
    int i,n,sum;
    cin>>n>>sum;
    vector<int> a(n);
    for(i=0;i<n;i++)
    cin>>a[i];
    triplets(a,sum);
}

int main()
{
    int t=1;
    cin>>t;
    while(t--)
        solve();
}