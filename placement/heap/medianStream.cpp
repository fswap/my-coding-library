#include <bits/stdc++.h>
using namespace std;

void medianStream(vector<int> a)
{
    int i,n=a.size();
    priority_queue<int> s;
    priority_queue<int,vector<int>,greater<int>> g;
    double med=a[0];
    s.push(a[0]);
    cout<<med<<" ";
    for(i=1;i<n;i++)
    {
        double x=a[i];
        if(s.size()>g.size())
        {
            if(x<med)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
            g.push(x);
            med=(s.top()+g.top())/2.0;
        }
        else if(s.size()==g.size())
        {
            if(x<med)
            {
                s.push(x);
                med=(double)s.top();
            }
            else
            {
                g.push(x);
                med=(double)g.top();
            }
        }
        else
        {
            if(x<med)
            s.push(x);
            else
            {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            med=(s.top()+g.top())/2.0;
        }   
        cout<<med<<" ";
    }
    cout<<endl;
}

void solve()
{
    int i,n;
    cin>>n;
    vector<int> a(n);
    for(i=0;i<n;i++)
    cin>>a[i];
    medianStream(a);
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