#include<cstdio>
#include<iostream>
using namespace std;

typedef long long ll;

#define MAXC 1010

ll M[6][3],N[MAXC][3];
ll dp[MAXC];

ll GetMVal(ll node,ll v)
{
	return M[node][0]*v*v+M[node][1]*v+M[node][2];
}

int main()
{
	
	freopen("in", "r", stdin);
	freopen("std.out", "w", stdout);
	ll n,m,C;
	scanf ("%lld %lld %lld",&n,&m,&C);
	for (ll i=1;i<=n;i++) scanf("%lld %lld %lld",&N[i][0],&N[i][1],&N[i][2]);
	for (ll i=1;i<=m;i++) scanf("%lld %lld %lld",&M[i][0],&M[i][1],&M[i][2]);
	for (ll i=1;i<=n;i++)
		for (ll j=C;j>=N[i][0];j--)
			for (ll k=1;k<=N[i][2];k++)
			{
				if (j-k*N[i][0]>=0) dp[j]=max(dp[j],dp[j-k*N[i][0]]+k*N[i][1]);
			}
	for (int i=0;i<=C;i++)
	printf("%lld\n",dp[i]);
	for (ll i=1;i<=m;i++) 
		for (ll j=C;j>=0;j--)
		{
			for (ll k=0;k<=j;k++)
			{
				dp[j]=max(dp[j],dp[j-k]+GetMVal(i,k));
			}
		}
	printf("%lld\n",dp[C]);
	return 0;
}
