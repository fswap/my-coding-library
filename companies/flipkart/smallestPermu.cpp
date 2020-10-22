#include <bits/stdc++.h>
using namespace std;

long long smallestPerm(long long n)
{
    int i,r,ans=0;
    vector<int> hash(10,0);
    while(n)
    {
        r=n%10;
        hash[r]++;
        n=n/10;
    }
    for(i=1;i<10;i++)
    {
        if(hash[i])
        {
            ans=i;
            hash[i]--;
            break;
        }
    }
    for(i=0;i<10;i++)
    {
        while(hash[i]--)
        ans=ans*10+i;
    }
    return ans;
}

void solve()
{
    long long n;
    cin>>n;
    cout<<smallestPerm(n)<<endl;
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

/*

string findSmallestPermutation(string s) 
{ 
    int len = s.length(); 
    sort(s.begin(), s.end()); 
    int i = 0; 
    while (s[i] == '0')  
        i++; 
      
    swap(s[0], s[i]); 
    return s; 
} 

*/