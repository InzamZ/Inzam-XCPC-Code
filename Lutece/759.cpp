//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
#define FREAD 1

const int maxn = 1e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 1e9 + 7;

#ifdef FREAD
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
#endif

int main()
{
    int T = 1, n, ans = 0, cur, res;
    T = _read();
    for (int i = 1; i <= T; ++i) {
        if (i != 1)
            putchar('\n');
        n = _read();
        ans = _read();
        cur = n * 2 - 1;
        res = 0;
        for (int j = 1; j < n; ++j)
            res += cur * j;
        if (res + n > ans)
            printf("-1");
        else {
            for (int i = 1; i < n; ++i)
                printf("%d ", i);
            printf("%d", ans - res);
        }
    }
    return 0;
}