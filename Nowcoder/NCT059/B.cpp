//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
const int maxn = 2e5 + 10;
int T = 1, n;
const ll mod = 998244353;
ll F[maxn][5], ans[maxn], f[5], inv[5];
int a[maxn][5], p[5] = {0, 2, 3, 1}, q[5] = {0, 3, 1, 2};

ll qpower(ll x, ll y)
{
    ll res = 1;
    while (y) {
        if (y & 1)
            res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

int main()
{
#ifdef LOCAL
    freopen("./out.txt", "w", stdout);
#endif
    // cin >> T;
    inv[1] = 1;
    inv[2] = qpower(2, mod - 2) % mod;
    inv[3] = qpower(3, mod - 2) % mod;
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%1d%1d%1d", &a[i][1], &a[i][2], &a[i][3]);
            a[i][0] = a[i][1] + a[i][2] + a[i][3];
        }
        F[n][3] = F[n][1] = F[n][2] = 1;
        for (int i = n - 1; i >= 1; --i) {
            for (int j = 0; j < 4; ++j) {
                F[i][j] = inv[a[i + 1][0]] * (a[i + 1][j] + a[i + 1][p[j]]) % mod;
                F[i][j] = F[i][j] * F[i + 1][j] % mod;
            }
        }
        for (int i = 1; i <= n; ++i) {
            ans[i] = 0;
            if (i == 1) {
                for (int j = 1; j < 4; ++j) {
                    if (a[i][j])
                        ans[i] += inv[a[i][0]] * F[i][j] % mod;
                    f[j] = a[i][j] * inv[a[i][0]] % mod;
                }
            }
            else {
                ll tmp[5];
                for (int j = 1; j < 4; ++j) {
                    if (a[i][j])
                        ans[i] = ans[i] + ((f[p[j]] * inv[a[i][0]] % mod) * F[i][j]  % mod);
                    tmp[j] = f[j];
                }
                for (int j = 1; j < 4; ++j) {
                    f[j] = (tmp[j]) * (a[i][j] + a[i][p[j]]) * inv[a[i][0]] % mod;
                    f[j] += ((tmp[p[j]]) * a[i][j] * inv[a[i][0]] % mod);
                    f[j] %= mod;
                }
            }
            printf("%lld%c", ans[i] % mod, (i == n) ? '\n' : ' ');
        }
    }
    return 0;
}