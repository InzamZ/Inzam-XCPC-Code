---
title: 力扣杯2022春季编程挑战赛
lang: zh-CN
description: 力扣杯2022春季编程挑战赛

---

# {{ $frontmatter.title }}

## A. 采集果实

### 题目大意

你需要摘水果 , 每次只摘一种 , 一次最多拿`limit`个 , 你每次需要摘`type`类水果`num`个 , 摘一次`type`类型水果花费`time[type]` . 问最后时间总和 . 

### 参考代码

签到题不解释 . 

```cpp
class Solution
{
public:
    int getMinimumTime(vector<int> &time, vector<vector<int>> &fruits, int limit)
    {
        int n = fruits.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            int t = fruits[i][1] / limit;
            if (fruits[i][1] % limit)
                ++t;
            t *= time[fruits[i][0]];
            ans += t;
        }
        return ans;
    }
};
```

## B. 信物传送

### 题目大意

地图上都是传送带 , 在上面你会移动到指向的方向 , 你可以在任意时间改变任意位置上的方向 , 你需要从指定的起点`start`到`end` , 问需要改变方向的最少的次数 . 

### 关键数据范围

地图尺寸小于等于$100 \times 100$

### 解题思路

从起点出发顺着传送带走 , 把经过的点全部放入队列中 . 如果没有经过终点 , 把队列里面的数一一拿出来 , 向每个方向走一次 , 此时我们操作多了一次 , 然后拓展的点顺着传送带走 , 检查是否到达终点 . 直到最后得到答案 . 

### 参考代码

```cpp
class Solution
{
public:
    vector<int> partx[10005];
    vector<int> party[10005];
    bool visited[105][105];
    int part[105][105];
    vector<string> mat;
    int conveyorBelt(vector<string> &matrix, vector<int> &start, vector<int> &end)
    {
        int partnum = 0;
        mat = vector<string>(matrix);
        for (int i = 0; i < matrix.size(); i++) {
            for (int k = 0; k < matrix[i].length(); k++) {
                visited[i][k] = false;
                part[i][k] = 0;
            }
        }
        partnum++;
        nxt(start[0], start[1], partnum);
        int cnt = 0;
        int lastcnt = 0;
        while (part[start[0]][start[1]] != part[end[0]][end[1]]) {
            cnt++;
            int l = partx[part[start[0]][start[1]]].size();
            for (int i = lastcnt; i < l; i++) {
                int x = partx[part[start[0]][start[1]]][i], y = party[part[start[0]][start[1]]][i];
                if (x != 0) {
                    if (part[x][y] != part[x - 1][y]) {
                        nxt(x - 1, y, ++partnum);
                        chan(part[x - 1][y], part[x][y]);
                    }
                }
                if (x != matrix.size() - 1) {
                    if (part[x][y] != part[x + 1][y]) {
                        nxt(x + 1, y, ++partnum);
                        chan(part[x + 1][y], part[x][y]);
                    }
                }
                if (y != 0) {
                    if (part[x][y] != part[x][y - 1]) {
                        nxt(x, y - 1, ++partnum);
                        chan(part[x][y - 1], part[x][y]);
                    }
                }
                if (y != matrix[0].size() - 1) {
                    if (part[x][y] != part[x][y + 1]) {
                        nxt(x, y + 1, ++partnum);
                        chan(part[x][y + 1], part[x][y]);
                    }
                }
            }
            lastcnt = l;
        }
        cnt = min(cnt, abs(start[0] - end[0]) + abs(start[1] - end[1]));
        return cnt;
    }
    void chan(int parta, int partb)
    {
        for (int i = 0; i < partx[parta].size(); i++) {
            part[partx[parta][i]][party[parta][i]] = partb;
            partx[partb].push_back(partx[parta][i]);
            party[partb].push_back(party[parta][i]);
        }
    }
    void nxt(int x, int y, int ppart)
    {
        if (visited[x][y])
            return ;
        part[x][y] = ppart;
        partx[ppart].push_back(x);
        party[ppart].push_back(y);
        visited[x][y] = true;
        if (mat[x][y] == '^') {
            if (x == 0)
                return;
            nxt(x - 1, y, ppart);
        }
        else if (mat[x][y] == 'v') {
            if (x == mat.size() - 1)
                return ;
            nxt(x + 1, y, ppart);
        }
        else if (mat[x][y] == '<') {
            if (y == 0)
                return;
            nxt(x, y - 1, ppart);
        }
        else {
            if (y == mat[0].length() - 1)
                return ;
            nxt(x, y + 1, ppart);
        }
    }
};
```

## C. 打地鼠

### 题目大意

打地鼠在九宫格进行 , 初始锤子在正中间 , 每次你可以移动1格 , 移动到地鼠上才能打到 . 地鼠会在`t[i]`时间出现在`(x[i],y[i])` , 问最后最多可以打到多少地鼠 . 

### 关键数据范围

地鼠出现时间 $0\leq t_i \leq 1e9$

地鼠个数 $0\leq moles.length \leq 1e5$

### 解题思路

我们可以考虑dp , 但是按照时间转移显然会超时 , 需要按照地鼠dp . dp状态设置为`dp[k][x][y]`   第 k 只地鼠出现后 , 锤子在位置`(x,y)`的情况下最多击打的地鼠数 . 

状态的转移不好用方程写出来 , 简单说就是首先计算两只地鼠出现时间差 , 然后在地鼠没有出现的时间内 , 状态的转移只会是锤子的移动 , 也就是锤到多的状态可以通过移动转移到别的位置 . 最后敲地鼠的操作就是指定位置状态自增就好了 . 

### 参考代码

```cpp
class Solution
{
public:
    int dp[200010][5][5];

    void update(int i, int j, int val, int t)
    {
        for (int k = 0; k < 3; ++k) {
            for (int l = 0; l < 3; ++l) {
                if (val < abs(i - k) + abs(j - l))
                    continue;
                dp[t][k][l] = max(dp[t][k][l], dp[t - 1][i][j]);
            }
        }
        return ;
    }

    static bool cmp1(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }

    int getMaximumNumber(vector<vector<int>> &moles)
    {
        vector<int>v;
        map<int, int>mp;
        sort(moles.begin(), moles.end(), cmp1);
        for (int i = 0; i < moles.size(); ++i) {
            v.push_back(moles[i][0]);
            mp[moles[i][0]] = i;
        }
        for (int k = 0; k < v.size(); ++k) {
            if (k != 0)
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if (moles[k][0] < abs(i - 1) + abs(j - 1))
                            continue;
                        update(i, j, v[k] - v[k - 1], k);
                    }
                }
            dp[k][moles[k][1]][moles[k][2]]++;
        }
        int ans = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (v[v.size() - 1] < abs(i - 1) + abs(j - 1))
                    continue;
                ans = max(ans, dp[v.size() - 1][i][j]);
            }
        }
        return ans;
    }
};
```



