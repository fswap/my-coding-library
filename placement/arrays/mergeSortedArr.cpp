#include<bits/stdc++.h>
using namespace std;

int next(int gap)
{
    if(gap<=1)
        return 0;
    return (gap/2)+(gap%2);
}

void merge(int a[],int b[],int n,int m)
{
    int i,j,gap=n+m;
    for(gap=next(gap);gap>0;gap=next(gap))
    {
        for(i=0;i+gap<n;i++)
        {
            if(a[i]>a[i+gap])
            swap(a[i],a[i+gap]);
        }
        for(j=(gap>n)?(gap-n):0;i<n and j<m;i++,j++)
        {
            if(a[i]>b[j])
            swap(a[i],b[j]);
        }
        if(j<m)
        {
            for(j=0;j+gap<m;j++)
            {
                if(b[j]>b[j+gap])
                swap(b[j],b[j+gap]);
            }
        }
    }
}

void solve()
{
    int i,n,m,j;
    cin>>n>>m;
    int a[n],b[m];
    for(i=0;i<n;i++)
    cin>>a[i];
    for(j=0;j<m;j++)
    cin>>b[j];
    merge(a,b,n,m);
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    for(j=0;j<m;j++)
    cout<<b[j]<<" ";
    cout<<endl;
}

int main()
{
    int t=1;
    cin>>t;
    while(t--)
        solve();
}