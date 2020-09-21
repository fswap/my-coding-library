#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
int n;
vector<int> ld,rd,col;

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
        if(!col[c] and !ld[r-c+n-1] and !rd[r+c])
        {
            board[r][c]=1;
            col[c]=ld[r-c+n-1]=rd[r+c]=1;
            ans=helper(r+1) or ans;
            board[r][c]=0;
            col[c]=ld[r-c+n-1]=rd[r+c]=0;
        }
    }
    return ans;
}

void nqueens()
{
    board=vector<vector<int>> (n,vector<int> (n,0));
    ld=vector<int> (n,0);
    rd=vector<int> (n,0);
    col=vector<int> (n,0);
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