//InzamZ
//
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 10;
const int MOD = 1e9 + 7;

long long qpow(long long a, int x)
{
    long long ans = 1, tmp = a;
    while (x) {
        if (x & 1) {
            ans *= tmp;
            ans %= MOD;
        }
        x >>= 1;
        tmp *= tmp;
        tmp %= MOD;
    }
    return ans % MOD;
}

long long inv[maxn];

int main()
{
    int T = 1, n;
    long long ans = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        inv[i] = qpow(i, MOD - 2);
    }
    int dn = n / 2;
    for (int i = 0; i < dn ; ++i) {
        ans *= n - i;
        ans %= MOD;
        // printf("%lld\n", ans);
    }
    for (int i = 0; i < dn ; ++i) {
        ans *= inv[i+1];
        ans %= MOD;
        // printf("%lld\n", ans);
    }
    printf("%lld\n", ans);
    return 0;
}