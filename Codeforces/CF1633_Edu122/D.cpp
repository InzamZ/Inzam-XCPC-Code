//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
#define FREAD 1

const int maxn = 1e6 + 10;
const int maxb = 1100;
const int inf = 12000;
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
int T = 1, n, ans = 0, k;
int b[maxn], c[maxn], f[maxn];
int a[maxb];
int main()
{
    T = _read();
    for (int i = 2; i <= 1000; ++i)
        a[i] = i - 1;
    a[1] = 0;
    for (int i = 2; i <= 1000; ++i) {
        for (int j = i / 2; j <= i; ++j) {
            for (int k = 1; k <= j; ++k) {
                if (j / k + j == i)
                    a[i] = min(a[i], a[j] + 1);
            }
        }
    }
    // printf("{ ");
    // for (int i = 1; i <= 1000; ++i)
    //     printf("%d, ", a[i]);
    // printf("}\n");
    while (T--) {
        ans = 0;
        n = _read(); k = _read();
        for (int i = 1; i <= n; ++i) {
            b[i] = _read();
            b[i] = a[b[i]];
        }
        for (int i = 1; i <= n; ++i)
            c[i] = _read();
        if (k >= inf) {
            for (int i = 1; i <= n; ++i)
                ans += c[i];
        }
        else {
            for (int i = 1; i <= n; ++i) {
                for (int j = k; j >= b[i]; --j)
                    f[j] = max(f[j], f[j - b[i]] + c[i]);
            }
            for (int j = k; j >= 0; --j)
                ans = max(ans, f[j]);

        }
        for (int j = k; j >= 0; --j)
            f[j] = 0;
        printf("%d\n", ans);
    }
    return 0;
}