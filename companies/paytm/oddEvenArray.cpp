#include <bits/stdc++.h>
using namespace std;

void insert(int* a,int n,int pos,int e)
{
    int temp=a[e];
    for(int i=e;i>pos;i--)
        a[i]=a[i-1];
    a[pos]=temp;
}

void arrange(int* a,int n)
{
    int i,j,od=-1,ev=-1;
    for(i=0;i<n;i++)
    {
        if(i%2)
        {
            for(j=od+1;j<n;j++)
            {
                if(a[j]%2)
                {
                    od=j;
                    break;
                }
            }
            insert(a,n,i,od);
        }
        else
        {
            for(j=ev+1;j<n;j++)
            {
                if(a[j]%2==0)
                {
                    ev=j;
                    break;
                }
            }
            insert(a,n,i,ev);
        }
    }
}

void solve()
{
    int i,j,n;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    arrange(a,n);
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