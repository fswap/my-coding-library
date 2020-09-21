#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
const int MOD = 1e9 + 7;

bitset<30> col,d1,d2;

void solveNQueen(int board[][10],int r,int n)
{
    if(r==n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			cout<<board[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl<<endl;
		return;
	}

    for(int c=0;c<n;c++)
	{
        if( !col[c] && !d1[r-c+n-1] && !d2[r+c])
		{
			board[r][c]=1;
            col[c] = d1[r-c+n-1] = d2[r+c] = 1;
            solveNQueen(board,r+1,n);
			board[r][c]=0;
            col[c] = d1[r-c+n-1] = d2[r+c] = 0;
        }
    }
}

void solve()
{
    int n;
    cin>>n;
	int board[10][10]={0};
	solveNQueen(board,0,n);
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