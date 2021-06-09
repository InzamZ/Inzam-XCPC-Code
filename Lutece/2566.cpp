#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
using ll = long long;
int pos[maxn];
ll fib[maxn], num;
int dp[maxn][2];

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
    // freopen("input.in", "r", stdin);
    // freopen("yours.out", "w", stdout);
    int n = 92, m, ans = 0;
    fib[1] = 1; fib[2] = 2;
    for (int i = 3; i <= 90; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];
    m = _read();
    for (int t = 1; t <= m ; ++t) {
        int cnt = 0;
        num = _read();
        for (int i = 90; i >= 1 && num; --i) {
            if (num >= fib[i])
                num -= fib[i], pos[++cnt] = i;
        }
        sort(pos + 1, pos + 1 + cnt);
        dp[1][1] = 1; dp[1][0] = (pos[1] - 1) / 2;
        for (int i = 2; i <= cnt; ++i) {
            dp[i][1] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][0] = (pos[i] - pos[i - 1] - 1) / 2 * dp[i - 1][1] + (pos[i] - pos[i - 1]) / 2 * dp[i - 1][0];
        }
        printf("%d\n", dp[cnt][1] + dp[cnt][0]);
    }
    return 0;
}