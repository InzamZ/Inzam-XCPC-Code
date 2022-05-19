---
title: CodeChef Starters 39
tags:
  - 贪心
---

# CodeChef Starters 39 Div4

## A - My very 1st contest!

### 题目大意

根据记分规则计数 . 

### 参考代码

```cpp
//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0, a[maxn], b[maxn];
vector<int>e[maxn], v;
string s;

int solve() {
    ans = 0;
    cin >> n >> m >> x;
    cout << n - m << ' ' <<n - m - x << '\n';
    return 0;
}

signed main() {
    FIO;
    // cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}
```

## B - Chess Ratings

### 解题思路

根据差值计算最少需要几场比赛才能到达指定Rating

### 参考代码

```cpp
//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0, a[maxn], b[maxn];
vector<int>e[maxn], v;
string s;

int solve() {
    ans = 0;
    cin >> n >> m;
    ans = (m - n) / 8 + ((m - n) % 8 ? 1 : 0);
    cout << ans << '\n';
    return 0;
}

signed main() {
    FIO;
    cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}
```

## C - A or B

### 解题思路

比较先解决 A 题或者 B 题 , 输出分数大者就好 . 

### 参考代码

```cpp
//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0, a[maxn], b[maxn];
vector<int>e[maxn], v;
string s;

int solve() {
    ans = 0;
    cin >> n >> m;
    cout << max(500ll - 2 * n + 1000ll - 4 * (n + m), 1000ll - 4 * m + 500 - 2 * (m + n)) << '\n';
    return 0;
}

signed main() {
    FIO;
    cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}
```

## D - Recent contest problems

### 解题思路

统计字符串出现次数并输出 . 

### 参考代码

```cpp
//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0, a[maxn], b[maxn];
vector<int>e[maxn],v;
string s;

int solve() {
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> s;
        if (s == "START38") ++ans;
    }
    cout << ans << ' ' << n - ans << '\n';
    return 0;
}

signed main()
{
    FIO;
    cin >> T;
    while (T--) {
    // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}
```

## E - Compress the Video

### 题目大意

压缩视频 , 相邻的帧如果相同可以只保留一帧 , 问最后最少可以只保留几帧 . 

### 解题思路

此时可以使用`unique`函数 , 这个函数如果使用有序数组可以去重 , 但是如果没有排序就是跟题目的意思相同 . 

### 参考代码

```cpp
//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0, a[maxn], b[maxn];
vector<int>e[maxn], v;
string s;

int solve() {
    ans = 0;
    cin >> n;
    v.clear();
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    v.resize(unique(v.begin(), v.end()) - v.begin());
    cout << v.size() << '\n';
    return 0;
}

signed main() {
    FIO;
    cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}
```

## F - Closest Vowels

### 题目大意

给定一个字符串 , 非元音字母可以变化成在字母表中与自己距离最近的元音字母 , 问字符串能变换成多少个不同的字符串 . 

### 解题思路

对于大多数字母都是只有唯一一个变换 , 除了跟两个元音字母的距离恰好相等 , 那么这些字母有两种选择 . 分别是`c`,`g`,`l`,`r`.

### 参考代码

```cpp
//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0, a[maxn], b[maxn];
vector<int>e[maxn],v;
string s;

int solve() {
    ans = 1;
    cin >> n >> s;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == 'c' || s[i] == 'g' || s[i] == 'l' || s[i] == 'r') 
        {
            ans = ans * 2 ;
            ans %= 1000000007ll;
        }
    }
    cout << ans << '\n';
    return 0;
}
//cglr
signed main()
{
    FIO;
    cin >> T;
    while (T--) {
    // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}
```

## G - Minimize Blocked Roads

### 题目大意

城市有病毒肆虐 , 城市之间如果有道路相连 , 病毒就会传播 . 城市地图是一张以节点`1`为根树图 , 边权为`1`的是政府可以关停的 , 为`0`则是政府无权关闭 , 必定开启的 . 问题是要使至多`k`座城市被感染 , 需要关闭的最少道路数量 . 

### 解题思路

由于是一棵树 , 从上到下关闭道路 , 贪心解法一定是越早关停越好 . 关停后这棵子树也就不受影响 , 里面边权为`1`的边也就无需考虑 . 所以只需要一次`DFS` , 记录最先到达的边权为`1`的边指向的子树大小 , 将这些子树大小排序 , 每次先去除指向子树大小最大的边 , 这样就可以使得关停的道路最少 . 

### 参考代码

```cpp
//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, k, ans = 0, a[maxn], b[maxn];
vector<pii>e[maxn];
vector<int>v;
string s;

int dfs(int rt, int flag, int fa) {
    int cnt = 1;
    for (auto &i : e[rt]) {
        if (i.first == fa)
            continue;
        if (!flag && i.second == 1)
            cnt += dfs(i.first, 1, rt);
        else if (flag == 1)
            cnt += dfs(i.first, 2, rt);
        else
            cnt += dfs(i.first, flag, rt);
    }
    if (flag == 1)
        v.push_back(cnt);
    return cnt;
}

int solve() {
    ans = 0;
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        e[u].push_back({v, x});
        e[v].push_back({u, x});
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    for (auto &i : v)
        ans += i;
    if (ans + k < n)
        cout << -1 << '\n';
    else {
        sort(v.begin(), v.end(), greater<int>());
        int len = 0;
        while (n > k)
            n -= v[len++];
        cout << len << '\n';
    }
    v.clear();
    return 0;
}

signed main() {
    FIO;
    cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}
```

## ExA - Even Subarray XOR

### 题目大意

你可以使用`300000`以内的正整数构造两个数组 , 每个数组的长度均为`N`并且每个数字仅能使用一次 . 要求对于任意的偶数前缀异或和 , 两数组都需要相等 . 多个答案输出任意一个 . 

### 解题思路

简单构造 , 第一个数组输出从`2`开始的偶数 , 第二个数组输出从`3`开始的奇数 , 即可求解 . 

### 参考代码

```cpp
//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0, a[maxn], b[maxn];
vector<int>e[maxn],v;
string s;

int solve() {
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cout << 2 * i << ' ';
    }
    cout << '\n';
    for (int i = 1; i <= n; ++i) {
        cout << 2 * i + 1<< ' ';
    }
    cout << '\n';
    return 0;
}

signed main()
{
    FIO;
    cin >> T;
    while (T--) {
    // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}
```



