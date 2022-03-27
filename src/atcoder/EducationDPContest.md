---
title: Atcoder Education DP Contest
date: 2021-03-24 10:44:51
updated: 2021-04-28 21:44:51
categories:
  - XCPC
  - Atcoder
tags:
  - 动态规划
---

> Atcoder上面的 DP 练习题 , 主要是能看到别人的代码 .

<!-- more -->

---

## A - Frog 1

### 解题思路

斐波那契数列 . 记得加绝对值 .状态转移方程 : 
$$
f_{i} = MAX (f_{i-1} + \lvert h_i - h_{i-1} \rvert \ ,\  f_{i-2} +\lvert h_i - h_{i-2} \rvert )
$$

### 代码

```cpp
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
		else if (i==2) dp[i]=abs(h[2]-h[1]);
		else dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));	
	}
	printf("%lld\n",dp[n]);
	return 0;
}
```

## B - Frog 2

### 解题思路

同 1 , 加上一个循环 k .状态转移方程 : 
$$
f_{i} = MAX ^{k}_{j=1} ( f_{i-j} + \lvert h_i - h_{i-j} \rvert)
$$

### 代码

```cpp
#include <cstdio>
#include <iostream>
using namespace std;

#define maxn 100010
#define INF 23333333333333
long long h[maxn],dp[maxn];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&h[i]);
		if (i!=1) dp[i]=INF;
		for (int j=1;j<=k && i-j>0;j++)
			dp[i]=min(dp[i-j]+abs(h[i]-h[i-j]),dp[i]);	
	}
	printf("%lld\n",dp[n]);
	return 0;
}
```



## C - Vacation

### 解题思路

- `dp[i][j]` : 第 i 天选择做 j 事件获得的最大值 . ( j = 1 做 a , 以此类推)

状态转移方程 : 
$$
dp_{i,j} = MAX ^{3}_{k = 1} ( dp_{i-1} + f(j)[i]) \tag{k != j} \\
f(x)=\left\{  
             \begin{array}{**lr**}  
             a &x=1 \\  
             b &x=2 \\
             c &x=3 \\   
             \end{array}  
\right.
$$

```cpp
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010
#define LINF 1e18
#define IINF 2147483647
using ll=long long;

ll dp[MAXN][4];
ll a,b,c,n;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a>>b>>c;
        if (i==1) 
        {
            dp[i][1]=a;
            dp[i][2]=b;
            dp[i][3]=c;
        }
        else 
        {
            dp[i][1]=max(dp[i-1][2]+a,dp[i-1][3]+a);
            dp[i][2]=max(dp[i-1][1]+b,dp[i-1][3]+b);
            dp[i][3]=max(dp[i-1][1]+c,dp[i-1][2]+c);
        }
    }
    cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<endl;
	return 0;
}
```

## D - Knapsack 1

### 解题思路

01背包 问题 . 使用滚动数组优化 .

- `dp[i]` 表示到上个物品选择完后 , 花费 i 个单位体积可获得的最大价值 . 
- `w` 当前物品占用体积
- `v` 当前物品价值

状态转移方程 : 
$$
dp[i]=\max (dp[i],dp[i-w]+v)
$$

### 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010
#define LINF 1e18
#define IINF 2147483647
using ll=long long;
ll dp[MAXN],w[MAXN],v[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int N,W;
    cin>>N>>W;
    for (int i=1;i<=N;i++) cin>>w[i]>>v[i];
    for (int i=1;i<=N;i++) 
    {
        for (int j=W;j>=w[i];j--)
        {
            dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[W]<<endl;
	return 0;
}
```

## E - Knapsack 2

### 解题思路

是 D 的加强版 , 数据太大了 , 原来的办法空间复杂度$O(W)$会 MLE , 于是可以换种思路 . 因为 n 和 v 非常小 ,我们可以计算价值为 i 时占用的空间 . 最后找到满足花费少于 W 的 i 的最大值即可.

- `dp[i]` 表示到上个物品选择完后 , 获得的 i 价值需要花费的最少空间 . 
- `w` 当前物品占用体积
- `v` 当前物品价值

状态转移方程 : 
$$
dp[x]=\left\{  
             \begin{array}{**lr**}  
             0 &x=0 \\  
             \infty &x\neq0
             \end{array}  
\right.\\
dp[i]=min(dp[i],dp[i-v]+w);
$$

### 代码

```cpp
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010
#define LINF 1e18
using ll = long long;
ll dp[MAXN], w, v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, W, ans=0;
    cin >> N >> W;
    for (int i = 0; i < MAXN; i++)
        dp[i] = LINF;
    dp[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> w >> v;
        for (int j = i * 1000; j >= v; j--)
        {
            dp[j] = min(dp[j], dp[j - v] + w);
        }
    }
    for (int i = 0; i < MAXN; i++)
        if (dp[i] <= W)
            ans = i;
    cout << ans << endl;
    return 0;
}
```



To Be Continued.

<!-- Q.E.D. -->