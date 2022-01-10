#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 210;
const int maxk = 1e3 + 10;
const ll mod = 1e9 + 7;
const ll inf = 1e17;
#define reg register
#define FOR(a,b,c) for(reg int a=b;a<=c;++a)

ll dp[maxn][maxn][maxk], num[maxn];
ll ans = 0, n, k, K;

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
    n = _read(); K = _read();
    FOR(i, 1, n) {
        num[i] = _read();
    }
    sort(num + 1, num + 1 + n);
    dp[1][0][0] = dp[1][1][0] = 1;
    for (int i = 2; i <= n; ++i)
        for (int j = 0; j <= i; ++j)
            for (int k = 0; k + j * (num[i] - num[i - 1]) <= K; ++k) {
                ll w = k + j * (num[i] - num[i - 1]);
                if (j != i)
                    dp[i][j + 1][w] += dp[i - 1][j][k];
                dp[i][j][w] += dp[i - 1][j][k];
                dp[i][j][w] += j * dp[i - 1][j][k];
                if (j)
                    dp[i][j - 1][w] += j * dp[i - 1][j][k];
                if (j != i)
                    dp[i][j + 1][w] %= mod;
                dp[i][j][w] %= mod;
                dp[i][j][w] %= mod;
                if (j)
                    dp[i][j - 1][w] %= mod;
            }
    FOR(i, 0, K) {
        ans += dp[n][0][i];
        ans %= mod;
    }
    printf("%lld\n", ans);
    return 0;
}