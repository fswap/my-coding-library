#include <bits/stdc++.h>
using namespace std;

#define ppi pair<int,pair<int,int>>

vector<int> mergeKSortedArr(vector<vector<int>> a)
{
    int i,k=a.size();
    vector<int> ans;
    priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
    for(i=0;i<k;i++)
        pq.push({a[i][0],{i,0}});
    while(!pq.empty())
    {
        ppi curr=pq.top();
        pq.pop();
        int r=curr.second.first;
        int c=curr.second.second;
        ans.push_back(curr.first);
        if(c+1<a[r].size())
        pq.push({a[r][c+1],{r,c+1}});
    }
    return ans;
}

void solve()
{
    int i,k=3;
    vector<vector<int>> a{  { 2, 6, 12 }, 
                            { 1, 9 }, 
                            { 23, 34, 90, 2000 } };
    vector<int> ans=mergeKSortedArr(a);
    for(auto x:ans)
    cout<<x<<" ";
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