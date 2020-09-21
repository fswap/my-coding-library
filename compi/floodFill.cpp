#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
const int MOD = 1e9 + 7;

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};
char screen[100][100];


void floodFill(int x,int y,int m,int n,char prevC,char newC)
{
    if(x<0 or x>=m or y<0 or y>=n)
        return;
    if(screen[x][y]!=prevC)
        return;
    screen[x][y]=newC;
    for(int i=0;i<4;i++)
    floodFill(x+dx[i],y+dy[i],m,n,prevC,newC);
}

void solve()
{
	int i,j,m,n,x,y;
    cin>>m>>n;
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    cin>>screen[i][j];
    cin>>x>>y; // (x,y) where color starts spreading
    char prevC='2',newC='3'; //  prevC- Previous Color, newC- New Color

    floodFill(x,y,m,n,prevC,newC);

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            cout<<screen[i][j]<<" ";
        cout<<endl;
    }
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