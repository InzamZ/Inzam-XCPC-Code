#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll mod = 998244353;

ll c[maxn];
__int128 a[15][maxn], b[15][maxn], sumb[15][maxn];
__int128 powten[25];
int typ[15];

int getbit(ll x)
{
    int cnt = 0;
    while (x)
        cnt++, x /= 10;
    return cnt;
}

int main()
{
    int T = 1, n;
    ll ans = 0;
    // scanf("%d", &T);
    powten[0] = 1;
    for (int i = 1; i <= 21; ++i)
        powten[i] = powten[i - 1] * 10;
    while (T--) {
        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%lld", &c[i]);
        for (int i = 1; i <= n; ++i) {
            int num = getbit(c[i]);
            typ[num]++;
            for (int j = 1; j <= 10; ++j) {
                a[j][i] += (c[i] / powten[j - 1] % 10) * powten[2 * j - 1] % mod;
                a[j + 1][i] = a[j][i];
                a[j][i] += (c[i] / powten[j]) * powten[2 * j] % mod;
            }
        }
        for (int i = 1; i <= n; ++i) {
            int num = getbit(c[i]);
            for (int j = 1; j <= 10; ++j) {
                b[j][i] += (c[i] / powten[j - 1] % 10) * powten[2 * (j - 1)] % mod;
                b[j + 1][i] = b[j][i];
                b[j][i] += (c[i] / powten[j]) * powten[2 * j] % mod;
            }
        }
        for (int j = 1; j <= 10; ++j)
            for (int i = 1; i <= n; ++i) {
                sumb[j][i] = sumb[j][i - 1];
                sumb[j][i] += b[j][i];
                sumb[j][i] %= mod;
            }
        for (int i = 1; i <= n; ++i) {
            int num = getbit(c[i]);
            ans += (sumb[num][n] % mod);
            ans %= mod;
            for (int j = 1; j <= 10; ++j) {
                ans += (1ll * a[j][i] * typ[j] % mod);
                ans %= mod;
            }
        }
        // for (int i = 1; i <= n; ++i) {
        //     putchar('\n');
        //     for (int j = 1; j <= 10; ++j)
        //         printf("[%d][%d] : %lld  %lld\n", j, i, b[j][i], a[j][i]);
        // }
        printf("%lld\n", ans % mod);
    }
    return 0;
}