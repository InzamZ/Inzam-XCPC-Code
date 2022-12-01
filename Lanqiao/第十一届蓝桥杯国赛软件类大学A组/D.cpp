#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int n, ans, cur;
int s[100025];

int gcd(int x,int y)
{
	if (y == 0) return x;
	return gcd(y,x%y);
}

int main()
{
	ans = 10000000;
	scanf("%d",&n);
	for (int i = 1;i <= n; ++i)
	{
		scanf("%d",&s[i]);
	}
	for (int i = 1; i <= n; ++i)
	{
		cur = s[i];
		if (cur == 1) ans = 0;
		for (int j = i + 1; j <= n; ++j)
		{
			if ( j - i >= ans) break;
			cur = gcd(cur,s[j]);
			//printf("i:%d j:%d %d\n",i,j,cur);
			if (cur == 1) ans = min( ans, j - i);
		}
	}
	//printf("%d\n",ans);
	if (ans == 10000000) {
		printf("%d\n",-1);
		return 0;
	}
	if (ans != 0 ) ans--;
	for (int i = 1;i <= n; ++i)
	{
		if (s[i] != 1) ans++;
	}
	printf("%d\n",ans);
	return 0;
} 
