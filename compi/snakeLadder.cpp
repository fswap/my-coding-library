#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
const int MOD = 1e9 + 7;

int solveSL(int moves[],int n)
{
    queue<int> q;
    vector<int> dis(n,-1);
    q.push(0);
    dis[0]=0;
    while(!q.empty())
    {
        int t=q.front();
        if(t==n-1)
            break;
        q.pop();
        for(int i=t+1;i<(t+6) && i<n;i++)
        {
            if(dis[i]==-1)
            {
                if(moves[i]!=-1)
                {
                    q.push(moves[i]);
                    dis[moves[i]]=dis[t]+1;
                }
                else
                {
                    q.push(i);
                    dis[i]=dis[t]+1;
                }
            }
        }
    }
    return dis[n-1];
}

void solve()
{
	int i,n=30;
    int moves[n];
    memset(moves,-1,sizeof moves);
    
    // Ladders 
    moves[2] = 21; 
    moves[4] = 7; 
    moves[10] = 25; 
    moves[19] = 28; 
  
    // Snakes 
    moves[26] = 0; 
    moves[20] = 8; 
    moves[16] = 3; 
    moves[18] = 6; 

    cout<<"Minimum moves to reach end="<<solveSL(moves,n)<<endl;
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