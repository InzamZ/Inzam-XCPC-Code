#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 10;
int val[maxn];

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
    int n, sum = 0, ans = 0;
    n = _read();
    for (int i = 1; i <= n; ++i) {
        val[i] = _read();
        sum += val[i];
    }
    if (sum % n != 0)
        ans = -1;
    else
        for (int i = 1; i <= n; ++i) {
            if (val[i] > sum / n)
                ++ans;
        }
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