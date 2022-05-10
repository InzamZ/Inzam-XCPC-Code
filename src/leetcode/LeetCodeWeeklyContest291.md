---
title: 力扣周赛291
lang: zh-CN
tags:
  - 贪心
  - 哈希
description: 力扣周赛291

---

# {{ $frontmatter.title }}
第一次打力扣周赛哈 , 事实上我是在尝试抽一顶冠军帽 . 然而翻车了 .

## A - [2259. 移除指定数字得到的最大结果](https://leetcode-cn.com/problems/remove-digit-from-number-to-maximize-result/)

### 题目大意

给定一个字符串整数 , 还有一个一位数 , 保证这个数字一定出现在字符串中 , 问在字符串整数中去掉这个数字后得到的最大数字是多少 ? 

### 解题思路

怎么去掉最合适呢 ? 首先明确一点 , 去除一个位置的数 , 不会影响前面的数位 , 只是跟后面的数位有关 . 那这个位置上去掉这个整数会使得后面的数位顶替上来 , 而要保证数字最大就要在顶替上来的数小于当前数的时候更换 . 考虑到可能没有满足的情况 , 就把最后一个给定的一位数删除就好了 . 

### 参考代码

```cpp
class Solution
{
public:
    string removeDigit(string number, char digit)
    {
        string ans = ""; int id = 0;
        for (int i = 0; i < number.size(); ++i) if (number[i] == digit) id = i;;
        for (int i = 0; i < number.size(); ++i) {
            if ( i == id || (number[i] == digit && number[i + 1] > digit)) {
                ans += number.substr(i + 1);
                break;
            }
            else
                ans += number[i];
        }
        return ans;
    }
};
```

## B - [2260. 必须拿起的最小连续卡牌数](https://leetcode-cn.com/problems/minimum-consecutive-cards-to-pick-up/)

### 题目大意

给一个数组 , 要求找出包含两个相同的数的最小连续区间长度 . 没有输出`-1` . 

### 解题思路

按照数字把每个数字出现的下标放入数组 , 最后遍历这些数组 , 求相邻元素距离的最小值 , 最后加`1` . 当然这样空间复杂度有冗余 , 所以可以只记录每个数最后出现的下标 , 每次遇到数字更新一次答案 . 其实无所谓 , 空间大差不差 . 

```cpp
class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        vector<int>v[1000010] ; int id = 0;
        for (auto x : cards)
            v[x].push_back(id++);
        int ans = -1;
        for (int i = 0; i < 1000001; ++i) {
            if (v[i].size() >= 2) {
                for (int j=1;j<v[i].size();++j) {
                    if (ans == -1) ans = v[i][j] - v[i][j - 1] + 1;
                    else ans = min(ans, v[i][j] - v[i][j - 1] + 1);
                }
            }
        }
        return ans;
    }
};
```

## C - [2261. 含最多 K 个可整除元素的子数组](https://leetcode-cn.com/problems/k-divisible-elements-subarrays/)

### 题目大意

一个数组`num` , 要求找出有多少不同的子数组 , 其中能被`p`整除的元素个数不超过`k`的 . 子数组定义是原数组连续的一部分 , 不同要求至少有一个下标对应的数字不同 . 

### 关键数据范围

$1 \leq num.length \leq 200$

### 解题思路

很小的数字 , 直接枚举区间暴力判断就好了 . 问题在于如何判重 . 还是因为很小直接使用字符串哈希解决 . 具体做法就是把数组转化成一个字符串 , 用`map`记录字符串是否出现 . 当然不能直接使用拼接 , 数字之间要有空格或者其他符号隔开 , 不然`918`会有歧义 , 可以是`[9,18]`或者`[91,8]`等等 . 

### 参考代码

```cpp
class Solution
{
public:
    int countDistinct(vector<int> &nums, int k, int p)
    {
        int ans = 0;
        map<vector<int>, int>mp;
        for (int i = 0; i < nums.size(); ++i) {
            vector<int>a;
            int cnt = 0;
            for (int j = i; j < nums.size(); ++j) {
                a.push_back(nums[j]);
                if (nums[j] % p == 0)
                    cnt++;
                if (cnt <= k && mp[a] == 0) {
                    ans++;
                    mp[a] = 1;
                }
            }
        }
        return ans;
    }
};
```

## D - [2262. 字符串的总引力](https://leetcode-cn.com/problems/total-appeal-of-a-string/)

### 题目大意

一个字符串的引力为字符串的组成字母种类个数 . 题目计算的是整个字符串`s`的子串的引力之和 . 

### 关键数据范围

$1\leq s.length \leq 1e5$

### 解题思路

数据范围大 , 无法使用暴力计算 . 于是乎需要使用其他方法 , 其实每个字母的贡献值是可以计算的 . 首先 , 如果这个字母之前完全没有出现过 , 那么之后包含它的子串 , 这个字母都会贡献`1`的引力 , 那么计算出包含它的子串数 . 字串可以表示成区间 , 左区间取值是前面从头到当前字母的下标 , 右区间是当前下标到结尾 , 那么子串数就是两者乘积 . 

如果不是第一次出现呢 , 那么子串只有在不包含之前任何一个当前字母的时候 , 当前的字母才会有贡献 . 因为第一次出现才会被计算贡献 , 那么修改一下左区间的取值就好了 , 就是上一个当前字母的出现下标加上一 . 

每个字母计算一次贡献 , 时间复杂度就是$O(Len(s))$ . 

### 参考代码

```cpp
class Solution
{
public:
    long long appealSum(string s)
    {
        long long ans = 0;
        queue<int>q[30];
        for (int i = 0; i <= 25; ++i)
            q[i].push(-1);
        for (int i = 0; i < s.size(); ++i)
            q[s[i] - 'a'].push(i);
        for (int i = 0; i <= 25; ++i)
            q[i].push(s.size());
        for (int i = 0; i <= 25; ++i) {
            while (!q[i].empty()) {
                int a = q[i].front();
                q[i].pop();
                if (q[i].empty())
                    break;
                int b = q[i].front();
                ans += 1ll * (b - a) * (s.length() - b);
            }
        }
        return ans;
    }
};
```

