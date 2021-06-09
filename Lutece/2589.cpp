#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e6 + 10;
using ll = long long;

int cnt = 0, trie[maxn << 2][2];
ll dp[35][2], ans = 0, num = 0;
vector<int>v[maxn << 2];

void ins(int x, int pos)
{
    int t = 0, nxt = 0;
    for (int i = 30; i >= 0; --i) {
        t = (x >> i) & 1;
        if (trie[nxt][t] == 0)
            trie[nxt][t] = ++cnt;
        nxt = trie[nxt][t];
        v[nxt].push_back(pos);
    }
    return ;
}

void dfs(int rt, int pos)
{
    if (pos == -1)
        return ;
    int ls = trie[rt][0], rs = trie[rt][1];
    ll lsiz = v[ls].size(), rsiz = v[rs].size();
    ll cur = 0, ans = 0;
    for (int i = 0; i < lsiz; ++i) {
        if (rsiz == 0)
            break;
        while (cur < rsiz && v[rs][cur] < v[ls][i])
            ++cur;
        ans += cur;
    }
    dp[pos][0] += ans;
    dp[pos][1] += lsiz * rsiz - ans;
    if (ls)
        dfs(ls, pos - 1);
    if (rs)
        dfs(rs, pos - 1);
}

int main()
{
    int n, x;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &x);
        ins(x, i);
    }
    dfs(0, 30);
    for (int i = 0; i <= 30; ++i) {
        if (dp[i][0] <= dp[i][1])
            ans += dp[i][0];
        else {
            ans += dp[i][1];
            num += (1 << i);
        }
    }
    printf("%lld %lld\n", ans, num);
    return 0;
}
