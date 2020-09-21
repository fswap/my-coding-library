#include <bits/stdc++.h>
using namespace std;

class minStack
{
    stack<int> st;
    stack<int> sp;

    public:
    void push(int a)
    {
        st.push(a);
        if(sp.empty() or sp.top()>=a)
            sp.push(a);
    }

    void pop()
    {
        if(st.empty())
            return;
        int ans=st.top();st.pop();
        if(sp.top()==ans)
            sp.pop();
    }

    int top()
    {
        if(st.empty())
            return -1;
        return st.top();
    }

    int getMin()
    {
        return sp.top();
    }
};

void solve()
{
    minStack s; 
    s.push(3); 
    s.push(5); 
    cout<<"Minimum :"<<s.getMin()<<endl; 
    s.push(2); 
    s.push(1); 
    cout<<"Minimum :"<<s.getMin()<<endl;
    s.pop(); 
    cout<<"Minimum :"<<s.getMin()<<endl;
    s.pop(); 
    cout<<"Top :"<<s.top()<<endl;
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