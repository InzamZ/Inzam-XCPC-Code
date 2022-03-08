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
int T = 1, n, ans = 0, m;
int f[maxb][2];

int main()
{
    n = _read();
    m = _read();
    if (n == 2 && m % 2 == 0)
        ans = 1;
    else if (n == 2)
        ans = 0;
    else if (m == 1)
        ans = 0;
    else {
        f[0][0] = 0;
        f[0][1] = 1;
        for (int i = 1; i <= m; ++i) {
            f[i][0] = f[i - 1][1] * (n - 1) + f[i - 1][0] * (n - 2);
            f[i][1] = f[i - 1][0];
        }
        ans = f[m][1];
    }
    printf("%d", ans);
    return 0;
}