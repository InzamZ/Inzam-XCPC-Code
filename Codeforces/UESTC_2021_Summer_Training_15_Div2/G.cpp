//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
// #define FREAD 1

const int maxn = 1010;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 998244353;

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

ll a[maxn][maxn], t[maxn][maxn];

int main()
{
    int T = 1;
    ll n, ans = 0, m, k;
    // scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%lld %lld %lld", &n, &m, &k);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                scanf("%lld", &a[i][j]);
                a[i][j] %= mod;
            }
        for (int i = 1; i <= k; ++i) {
            int b;
            ll c;
            char z[5];
            scanf("%s %d %lld", z, &b, &c);
            if (z[0] == 'r') {
                for (int j = 1; j <= m; ++j) {
                    ans += (((c - t[b][j]) % mod) * a[b][j] % mod);
                    ans %= mod;
                    t[b][j] = c;
                }
            }
            if (z[0] == 'c') {
                for (int j = 1; j <= n; ++j) {
                    ans += (((c - t[j][b]) % mod) * a[j][b] % mod);
                    ans %= mod;
                    t[j][b] = c;
                }
            }
        }
        printf("%lld\n", ans % mod);
    }
    return 0;
}