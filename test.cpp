#include<bits/stdc++.h>
using namespace std;
#define INF 10000000
 
int dp[25][30],n,h,f,s,a[25],ans,cnt=1;
 
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<30;j++)
            dp[i][j]=INF;
    cin>>h>>s>>f;
    for(int i=0;i<n;i++)
        cin>>a[i];
    dp[0][a[0]]=(h+s)*a[0];
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<30;j++)
        {
            if(dp[i][j]!=INF)
            {
                if(a[i+1]>j)
                dp[i+1][a[i+1]]=min(dp[i+1][a[i+1]],dp[i][j]+s*a[i+1]+h*(a[i+1]-j));
                else
                {
                    for(int k=j;k>=a[i+1];k--)
                    dp[i+1][k]=min(dp[i+1][k],dp[i][j]+s*k+(j-k)*f);
                }
            }
        }
    }
    ans=INF;
    for(int i=0;i<30;i++)
        ans=min(dp[n-1][i],ans);
    cout<<ans<<endl;
}