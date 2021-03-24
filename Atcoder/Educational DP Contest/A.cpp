#include <cstdio>
#include <iostream>
using namespace std;

#define maxn 100010
long long h[maxn],dp[maxn];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&h[i]);
		if (i==1) continue;
		else if (i==2) abs(dp[i]=h[2]-h[1]);
		else dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));	
	}
	printf("%lld\n",dp[n]);
	return 0;
}