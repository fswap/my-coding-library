#include <bits/stdc++.h>
using namespace std;

vector<int> lps;

void LPS(string pat)
{
    int m=pat.size();
    lps=vector<int> (m);
    lps[0]=0;
    int i=1,len=0;
    while(i<m)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i++]=len;
        }
        else
        {
            if(len==0)
            lps[i++]=0;
            else
            len=lps[len-1];
        }   
    }
}

void KMP(string str,string pat)
{
    LPS(pat);
    int i=0,j=0,n=str.size(),m=pat.size();
    while(i<n)
    {
        if(str[i]==pat[j])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            cout<<"Pattern is present at "<<i-m<<endl;
            j=lps[j-1];
        }
        else if(i<n and str[i]!=pat[j])
        {
            if(j==0)
            i++;
            else
            j=lps[j-1];
        }  
    }
}

void solve()
{
    string str,pat;
    getline(cin,str);
    getline(cin,pat);
    KMP(str,pat);
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