#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e4 + 10;
int ansx, ansy, val[maxn];
bitset<maxn>vis[maxn];

inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int _read()
{
    char ch = nc(); int sum = 0;
    while (!(ch >= '0' && ch <= '9'))
        ch = nc();
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}

void solve()
{
    int n, mx, mn, lx = 0, ly = 0, rx, ry;
    ansx = ansy = 1e9;
    n = _read();
    for (int i = 1; i <= n; ++i) {
        val[i] = _read();
        if (i == 1)
            mx = mn = val[i];
        else {
            mx = max(mx, val[i]);
            mn = min(mn, val[i]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (val[i] == mn) {
            if (lx == 0)
                lx = i;
            rx = i;
        }
    }
    for (int i = n; i > 0; --i) {
        if (val[i] == mx) {
            if (ly == 0)
                ly = i;
            ry = i;
        }
    }
    int ans = 1e9;
    ans = min(lx + n -  ry + 1, ly + n -  rx + 1);
    ans = min(ans, n + 1 - min(rx, ry));
    ans = min(max(lx, ly), ans);
    ans = min(ans, lx + (n - ry + 1));
    ans = min(ans, ly + (n - rx + 1));
    printf("%d\n", ans);
    return ;
}

int main()
{
    int T = 1;
    T = _read();
    while (T--)
        solve();
    return 0;
}