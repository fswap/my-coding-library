#include <bits/stdc++.h>
using namespace std;

class minStack
{
    int minEle;
    stack<int> st;
    public:
    void push(int a)
    {
        if(st.empty())
        {
            st.push(a);
            minEle=a;
        }
        else
        {
            if(a<minEle)
            {
                st.push(2*a-minEle);
                minEle=a;
            }
            else
            st.push(a);
        }
    }

    void pop()
    {
        if(st.empty())
            return;
        int tp=st.top();st.pop();
        if(tp<minEle)
            minEle=2*minEle-tp;
    }

    int top()
    {
        if(st.empty())
            return -1;
        int tp=st.top();
        if(tp<minEle)
            return minEle;
        else
            return tp;
    }

    int getMin()
    {
        if(st.empty())
            return -1;
        return minEle;
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