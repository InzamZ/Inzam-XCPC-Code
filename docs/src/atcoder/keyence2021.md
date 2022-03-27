---
title: KEYENCE Programming Contest 2021
date: 2021-01-29 16:01:04
updated: 2021-01-30 16:13:39
categories:
  - XCPC
  - Atcoder
tags:
  - 贪心
  - 动态规划
---

<!-- more -->

---

## A - Two Sequences 2

贪心。因为数据都是正数，我们要求乘积最大，只要取上一次的最大值和新增的组合比较大小即可。当然直接写出来是$O( N^2 )$的时间复杂度，TLE是必然的。对于新增的组合，b是固定的，那么我们在读入a时进行预处理取a数组目前的最大值。时间复杂度是$O(N)$。

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define maxn 200010
ll a[maxn],ans;

int main()
{
	ll n,b;
	cin>>n;
	for (int i=1;i<=n;i++)		
	{
		scanf("%lld",&a[i]);
		a[i]=max(a[i],a[i-1]);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&b);
			ans=max(ans,b*a[i]);
		printf("%lld\n",ans);
	}
	return 0;
} 
```

## B - Mex Boxes

记录每一个数字的球有几个$a[i]$，从0开始枚举，更新k为当前还能维护的连续数组数。当k大于数字 i 出现次数，那么答案就要加上$i*(k-a[i])$。

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define maxn 300010
int a[maxn];
ll ans=0ll;

int main()
{
	int n,k,x;
	cin>>n>>k;
	for (int i=1;i<=n;i++)		
	{
		scanf("%d",&x);
		++a[x];
	}
	for (ll i=0;i<=n && k;i++)
	{
		if (k>a[i]) 
		{
			ans=ans+(ll)(k-a[i])*i;
			k=a[i];
		}
	}
	printf("%lld\n",ans);
	return 0;
} 
```

## C - Robot on Grid

一道 dp 题目，优化用到了逆元求大数取 mod。其实我们就是先求算出到终点总共有多少路线，这是一个简单的dp问题，因为只有两种情况，向下和向右，外加判断所在位置字母。但是算填写方法时，你必须知道有多少格子你可以自由填写。那么你还要记录当前你经过了多少个空白格。

- dp\[h]\[w]\[k] 表示到达（h , w）且经过 k 个空白格的路线数。

时间复杂度$O(HW(H+W))$。这个算法显然是超时的，但是我们研究一下公式。
$$
\begin{aligned}
&\sum^{h+w}_{k=1}dp[h][w][k]*2^k*3^{hw-K-k}\\
=&\sum^{h+w}_{k=1}dp[h][w][k]*(\frac{2}{3})^{k}*3^{hw-K}\\
\end{aligned}
$$
所以只需要在你走上空白格时，把路线数乘以$\frac{2}{3}$即可。而除法取余，我们只要找到 3 的逆元就好了。现在时间复杂度直接降到了$O(HW)$。

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define maxn 5005
#define mod 998244353
char imap[maxn][maxn];
ll dp[maxn][maxn];
ll qpow(ll a,ll n)
{
	ll ans=1;
	while (n)
	{
		if ( n & (ll)1) ans=ans*a%mod;
		a=a*a%mod;
		n>>=1;
	}
	return ans%mod;
}

int main()
{
	int H,W,K,h,w;
	char k;
	cin>>H>>W>>K;
	for (int i=1;i<=K;i++)		
	{
		scanf("%d %d %c",&h,&w,&k);
		imap[h][w]=k;
	}
	ll inv=qpow(3,mod-2);
	dp[1][1]=1;
	for (int i=1;i<=H;i++)
	{
		for (int j=1;j<=W;j++)
		{
			if (imap[i][j]=='R'||imap[i][j]=='X') 
                dp[i][j+1]=(dp[i][j]+dp[i][j+1] )%mod;
			if (imap[i][j]=='D'||imap[i][j]=='X') 
                dp[i+1][j]=(dp[i][j]+dp[i+1][j] )%mod;
			if (imap[i][j]=='\0') 
			{
				dp[i][j+1]=((dp[i][j]*2%mod)*inv%mod+dp[i][j+1])%mod;
				dp[i+1][j]=((dp[i][j]*2%mod)*inv%mod+dp[i+1][j])%mod;
			}
		}
	}
	printf("%lld\n",qpow(3,H*W-K)*dp[H][W]%mod);
	return 0;
} 
```

---

To Be Continued.

<!-- Q.E.D. -->