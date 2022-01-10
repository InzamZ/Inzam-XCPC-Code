#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
using ll = __int128;

ll num[maxn][maxn], ans = 0;
ll dp[maxn][maxn], base[maxn];

inline void print(__int128 x)
{
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

inline __int128 read()
{
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int main()
{
    base[0] = 1L;
    for (int i = 1; i <= 100; ++i)
        base[i] = base[i - 1] * 2;
    ll n, m;
    n = read();
    m = read();
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            num[i][j] = read();
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= m; ++i) {//beg & end
            for (int j = m; j >= i; --j)
                dp[i][j] = max(dp[i - 1][j] + base[m - j + i - 1] * num[k][i - 1], dp[i][j + 1] + base[m - j + i - 1] * num[k][j + 1]);
        }
        ll rans = 0;
        for (int i = 1; i <= m; ++i)
            rans = max(rans, dp[i][i] + num[k][i] * base[m]);
        ans += rans;
    }
    print(ans);
    return 0;
}