#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {

ll t=1;
//cin>>t;
while(t--)
{
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll>v[n+1];
    ll i,j;
    unordered_map<ll,unordered_map<ll,ll>>mp;
    for(i=0;i<n;i++)
    {
        ll x,y,c;
         cin>>x>>y>>c;
         v[x].push_back(y);
         v[y].push_back(x);
         mp[x][y]=c;
         mp[y][x]=c;
    }
    
   vector<vector<ll>>dist(k+1,vector<ll>(n+1,INT_MAX));
   for(i=0;i<=k;i++)
     dist[i][1]=0;
     
   for(i=0;i<=k;i++)
   {
       list<pair<ll,ll>>l;
       l.push_back({1,0});
       while(!l.empty())
       {
           ll x=l.front().first;
           ll lev=l.front().second;
           l.pop_front();
           ll temp=v[x].size();
           for(j=0;j<temp;j++)
           {
               ll q=v[x][j];
               
               if(i==0)
               {
                   if(dist[i][q]>dist[i][x]+mp[x][q])
                   {
                       dist[i][q]=dist[i][x]+mp[x][q];
                       l.push_back({q,lev+1});
                   }
                   continue;
               }
               
               if(dist[i][q]!=0)
               {
                   if(lev+1<=i)
                   {
                       dist[i][q]=0;
                       l.push_back({q,lev+1});
                      
                   }
                   else{
                       ll temp=min(dist[i][x]+mp[x][q],dist[i-1][x]);
                       if(dist[i][q]>temp)
                       {
                           dist[i][q]=temp;
                            l.push_back({q,lev+1});
                       }
                   }
                   
               }
              
               
           }
           
       }
   }
for(i=1;i<=n;i++)
cout<<dist[k][i]<<" ";
    
}
return 0;
}