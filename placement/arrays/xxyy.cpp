#include<bits/stdc++.h>
using namespace std;

int count(int X,int y[],int n,int hash[])
{
    if(X==0)
        return 0;
    if(X==1)
        return hash[0];
    auto it=upper_bound(y,y+n,X)-y;
    int cnt=n-it;
    cnt+=hash[0]+hash[1];
    if(X==2)
    cnt-=hash[3]+hash[4];
    if(X==3)
    cnt+=hash[2];
    return cnt;
}

void solve()
{
    int m,n,i,j;
    cin>>m>>n;
    int x[m],y[n],hash[5]={0};
    for(i=0;i<m;i++)
    cin>>x[i];
    for(i=0;i<n;i++)
    {
        cin>>y[i];
        if(y[i]<5)
        hash[y[i]]++;
    }
    sort(y,y+n);
    int ans=0;
    for(i=0;i<m;i++)
    ans+=count(x[i],y,n,hash);
    cout<<ans<<endl;
}

int32_t main()
{
    int t=1;
    cin>>t;
    while(t--)
        solve();
}