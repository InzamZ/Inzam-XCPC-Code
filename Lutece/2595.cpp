#include <bits/stdc++.h>
using namespace std;

#define mod 998244353
using ll = long long;
ll a[30];
ll L, R, N;

struct node {
    ll sum = -1, num = -1;
    node() : sum(-1), num(-1) {}
    node(ll a, ll b) : sum(a), num(b) {}
} dp[70][2000];

int cntcol(ll x)
{
    int cnt = 0;
    while (x) {
        if (x & 1)
            ++cnt;
        x >>= 1;
    }
    return cnt;
}
ll qpow(ll x)
{
    ll ans = 1, cnt =10;
    while (x) {
        if (x & 1) {
            ans *= cnt;
            ans %= mod;
        }
        cnt *= cnt; cnt %= mod;
        x >>= 1;
    }
    return ans;
}

node dfs(int pos, int col, bool limit, bool lead)
{
    if (pos == -1)
        return node(0, 1);
    if (!limit && !lead && dp[pos][col].num != -1)
        return dp[pos][col];
    int up = limit ? a[pos] : 9;
    ll isum = 0, inum = 0, sumx = qpow(pos);
    node ans = node(0, 0);
    for (int i = 0; i <= up; i++) {
        if (lead && i == 0 && cntcol(col) <= N) {
            ans = dfs(pos - 1, 0, limit && i == a[pos], lead && i == 0);
            isum += (sumx * i * ans.num + ans.sum);
            inum += ans.num;
            isum %= mod;
            inum %= mod;
        }
        else if (cntcol(col | (1 << i)) <= N) {
            ans = dfs(pos - 1, col | (1 << i), limit && i == a[pos], lead && i == 0);
            isum += (sumx * i * ans.num + ans.sum);
            inum += ans.num;
            isum %= mod;
            inum %= mod;
        }
    }
    if (!limit && !lead)
        dp[pos][col] = node(isum % mod, inum % mod);
    return node(isum % mod, inum % mod);
}
ll solve(ll x)
{
    int cnt = 0;
    while (x) {
        a[cnt++] = x % 10;
        x /= 10;
    }
    return dfs(cnt - 1, 0, true, true).sum;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    scanf("%lld %lld %lld", &L, &R, &N);
    printf("%lld\n", ((solve(R) - solve(L - 1)) % mod + mod) % mod);
    return 0;
}