#include<bits/stdc++.h>
using namespace std;

#define int long long

int merge(int a[],int l,int m,int h)
{
    int i=l,j=m+1,k=0,cnt=0;
    int temp[h-l+1];
    while(i<=m and j<=h)
    {
        if(a[i]<=a[j])
        temp[k++]=a[i++];
        else if(a[i]>a[j])
        {
            temp[k++]=a[j++];
            cnt+=m-i+1;
        }
    }
    while(i<=m)
    temp[k++]=a[i++];
    while(j<=h)
    temp[k++]=a[j++];
    for(i=0;i<k;i++)
    a[i+l]=temp[i];
    return cnt;
}

int inversions(int a[],int l,int h)
{
    int ans=0;
    if(l<h)
    {
        int m=l+(h-l)/2;
        ans+=inversions(a,l,m);
        ans+=inversions(a,m+1,h);
        ans+=merge(a,l,m,h);
    }
    return ans;
}

void solve()
{
    int i,n;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<inversions(a,0,n-1)<<endl;
}

int32_t main()
{
    int t=1;
    cin>>t;
    while(t--)
        solve();
}