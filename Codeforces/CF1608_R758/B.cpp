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
const int maxb = 1e4;
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

int ans[maxn];

int main()
{
    int T = 1, n, a, b;
    T = _read();
    while (T--) {
        n = _read(); a = _read(); b = _read();
        if ((a + b > n - 2 || max(a, b) >= (n + 1) / 2) )
            printf("-1\n");
        else if (abs(a - b) > 1)
            printf("-1\n");
        else if (a==b && b==0)
        {
            for (int i = 1; i <= n; ++i)
                printf("%d%c", i, i == n ? '\n' : ' ');
        }
        else if (a == b ) {
            int res = 1;
            for (int i = 1; i <= a + b + 2; i += 2) {
                ans[i] = res;
                ++res;
            }
            for (int i = 2; i <= a + b + 2; i += 2) {
                ans[i] = res;
                ++res;
            }
            for (int i = a + b + 3; i <= n; ++i)
                ans[i] = i;
            for (int i = 1; i <= n; ++i)
                printf("%d%c", ans[i], i == n ? '\n' : ' ');
        }
        else if (a > b) {
            int res = 1;
            for (int i = 1; i <= a + b + 2; i += 2) {
                ans[n] = ans[i] = res;
                ++res;
            }
            for (int i = 2; i <= a + b + 2; i += 2) {
                ans[i] = res;
                ++res;
            }
            for (int i = a + b + 3; i <= n; ++i)
                ans[i - 1] = i;
            for (int i = 1; i <= n; ++i)
                printf("%d%c", ans[i], i == n ? '\n' : ' ');
        }
        else {
            int res = a + b + 2;
            for (int i = 1; i <= a + b + 2; i += 2) {
                ans[i] = res;
                --res;
            }
            for (int i = 2; i <= a + b + 2; i += 2) {
                ans[i] = res;
                --res;
            }
            for (int i = a + b + 3; i <= n; ++i)
                ans[i] = i;
            for (int i = 1; i <= n; ++i)
                printf("%d%c", ans[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}