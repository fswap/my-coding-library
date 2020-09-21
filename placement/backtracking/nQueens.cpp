#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
int n;

bool isSafe(int r,int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        if(board[i][c])
        return false;
    }
    for(i=r,j=c;i>=0 and j>=0;i--,j--)
    {
        if(board[i][j])
        return false;
    }
    for(i=r,j=c;i>=0 and j<n;i--,j++)
    {
        if(board[i][j])
        return false;
    }
    return true;
}

bool helper(int r)
{
    if(r==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            cout<<board[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    bool ans=false;
    for(int c=0;c<n;c++)
    {
        if(isSafe(r,c))
        {
            board[r][c]=1;
            ans=helper(r+1) or ans;
            board[r][c]=0;
        }
    }
    return ans;
}

void nqueens()
{
    int i,j;
    board=vector<vector<int>> (n,vector<int> (n,0));
    if(helper(0)==false)
    {
        cout<<"Not Possible :("<<endl;
        return;
    }
}

void solve()
{
    cin>>n;
    nqueens();
}

int32_t main()
{
    int t=1;
    //cin>>t;
    while(t--)
        solve();
}