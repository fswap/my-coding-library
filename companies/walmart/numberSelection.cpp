#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>

const int MOD = 1e9+7; 

int n;

vvi multiply(vvi A,vvi B)
{
	int i,j,k;
	vvi C(n+1,vi (n+1,0));
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	for(k=1;k<=n;k++)
	{
		C[i][j]=(C[i][j]+(A[i][k]*B[k][j])%MOD)%MOD;
	}
	return C;
}

vvi matrixExpo(vvi A,int p)
{
	if(p==1)
	return A;
	else if(p&1)
	return multiply(A,matrixExpo(A,p-1));
	else
	{
		vvi X=matrixExpo(A,p/2);
		return multiply(X,X);
	}
}

void solve()
{
	int i,j,x,ans=0;
	n=2;
	vi b(n+1),c(n+1);
	b[1]=b[2]=1;
	c[1]=c[2]=1;
	cin>>x;
    x+=2;
	if(x<=n)
	{
		cout<<b[x]<<endl;
		return;
	}
	vvi T(n+1,vi (n+1));
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i<n)
			T[i][j]=(j==i+1);
			else
			T[i][j]=c[n-j+1];
		}
	}
	T=matrixExpo(T,x-1);
	for(i=1;i<=n;i++)
	ans=(ans+(T[1][i]*b[i])%MOD)%MOD;
	cout<<ans-1<<endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	t=1;
	cin>>t;
	while(t--)
		solve();
}