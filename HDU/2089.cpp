#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
using ll = long long;

int bi[maxn];
int dp[maxn][5];

ll dfs(int pos, bool pre, int sta, bool limit)
{
    if (pos == -1 )
        return 1;
    if (!limit  && dp[pos][pre] != -1)
        return dp[pos][pre];
    int up = limit ? bi[pos] : 9;
    ll ans = 0;
    for (int i = 0; i <= up; ++i) {
        if ( sta == 6  &&  i == 2 )
            continue;
        if (sta == 4)
            continue;
        ans += dfs(pos - 1,  i == 6 ? 1 : 0, i, limit && i == bi[pos]);
    }
    if (!limit)
        dp[pos][pre] = ans;
    return ans;
}

ll solve(int x)
{
    int pos = 0;
    memset(dp, -1, sizeof(dp));
    while (x)
        bi[pos++] = x % 10, x /= 10;
    return dfs(pos - 1, 0, -1, true);
}

int main()
{
    ll a, b, ans;
    while (scanf("%lld %lld", &a, &b) && a && b) {
        ans = solve(b) - solve(a - 1);
        printf("%lld\n",  ans);
    }
    return 0;
}