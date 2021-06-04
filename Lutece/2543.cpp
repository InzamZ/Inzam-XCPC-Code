#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 2010;
const ll inf = 1e17;
#define reg register

ll dp[maxn][maxn], imap[maxn][maxn];
ll ans = inf, n;

inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline ll _read()
{
    char ch = nc(); ll sum = 0;
    while (!(ch >= '0' && ch <= '9'))
        ch = nc();
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}

int main()
{
    n = _read();
    for (reg int i = 1; i < n; ++i) {
        for (reg int j = i + 1; j <= n; ++j)
            imap[i][j] = _read();
    }
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            dp[i][j] = inf;
    dp[1][1] = 0;
    for (reg int i = 1; i < n; ++i)
        for (reg int j = 1; j <= i; ++j) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + imap[i][i + 1]);
            dp[i][i] = min(dp[i][i], dp[i][j] + imap[j][i]);
            dp[i + 1][i] = min(dp[i + 1][i], dp[i][j] + imap[j][i + 1]);
        }
    for (int i = 1; i <= n; ++i)
        ans = min(ans, dp[n][i]);
    printf("%lld\n", ans);
    return 0;
}