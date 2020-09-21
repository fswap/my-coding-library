#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int i,n,j,k,cnt=0;
    cin>>n;
    vector<int> a(n);
    for(i=0;i<n;i++)
    cin>>a[i];
    sort(a.begin(),a.end());
    for(i=0;i<n;i++)
    {
        j=0,k=i-1;
        while(j<k)
        {
            if(a[j]+a[k]==a[i])
            {
                cnt++;
                k--;j++;
            }
            else if(a[j]+a[k]<a[i])
            j++;
            else
            k--;
        }
    }
    if(cnt)
    cout<<cnt<<endl;
    else
    cout<<-1<<endl;
}

int main()
{
    int t=1;
    cin>>t;
    while(t--)
        solve();
}