#include<cstdio>
#include<iostream>
using namespace std;

typedef int ll;

#define MAXC 10010

ll M[6][3],N[MAXC*8][3];
ll dp[MAXC];

inline ll GetMVal(ll node,ll v)
{
	return M[node][0]*v*v+M[node][1]*v+M[node][2];
}

int main()
{
    
    // freopen("in", "r", stdin);
    // freopen("yours.out", "w", stdout);
	ll n,m,C,cur;
	scanf ("%d %d %d",&n,&m,&C);
	cur=n;
	for (ll i=1;i<=n;i++) {
		scanf("%d %d %d",&N[i][0],&N[i][1],&N[i][2]);
	}
	for (int i=1;i<=n;i++)
	{
		int cnt=1;
		while(N[i][2]-cnt>0)
		{
			N[++cur][0]=N[i][0]*cnt;
			N[cur][1]=N[i][1]*cnt;
			N[i][2]-=cnt;
			cnt*=2;
		}
		N[i][0]*=N[i][2];
		N[i][1]*=N[i][2];
	}
	for (ll i=1;i<=m;i++) scanf("%d %d %d",&M[i][0],&M[i][1],&M[i][2]);
	for (ll i=1;i<=cur;i++)
		for (ll j=C;j>=N[i][0];j--)
				dp[j]=max(dp[j],dp[j-N[i][0]]+N[i][1]);
    for (int i=0;i<=C;i++)
	printf("%d\n",dp[i]);
	for (ll i=1;i<=m;i++) 
		for (ll j=C;j>=0;j--)
		{
			for (ll k=0;k<=j;k++)
			{
				dp[j]=max(dp[j],dp[j-k]+GetMVal(i,k));
			}
		}
	printf("%d\n",dp[C]);
	return 0;
}