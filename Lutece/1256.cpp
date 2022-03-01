//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
#define FREAD 1

const int maxn = 2e3 + 10;
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

int cnt[maxb][maxn];

int main()
{
    int T = 1, n, ans = 0, m, q, l, r;
    // T = _read();
    while (T--) {
        ans = 0;
        n = _read();
        m = _read();
        for (int i = 1; i <= n; ++i) {
            ans = _read();
            for (int j = 1; j <= m; ++j) {
                if (j == ans)
                    cnt[j][i] = cnt[j][i - 1] + 1;
                else
                    cnt[j][i] = cnt[j][i - 1];
            }
        }
        q = _read();
        while (q--) {
            ans = 0;
            l = _read(); r = _read();
            for (int i = 1; i <= m; ++i) {
                if (cnt[i][r] - cnt[i][l - 1])
                    ++ans;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}