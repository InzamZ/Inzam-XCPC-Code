//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e6 + 10;
ll f[maxn];

int main()
{
    int T = 1;
    ll n, k, ans = 0;
    // T=_read();
    while (T--) {
        f[1] = 1;
        ans = 0;
        scanf("%lld %lld", &n, &k);
        if ( n == 1 && k == 1)
            printf("1\n");
        else if (k == 1)
            printf("%lld\n", n);
        else if (n == 1)
            printf("-1\n");
        else if (k > 2e5 || n < k * (k + 1) / 2)
            printf("-1\n");
        else {
            for (ll i = 2; i <= k && i <= 2e5; ++i)
                f[i] = f[i - 1] + i;
            ll res = n / f[k];
            ans = 1;
            for (ll i = 1; i * i <= n; ++i) {
                if (n % i == 0 ) {
                    if (n / i <= res)
                        ans = max(ans, n / i);
                    else if (i <= res)
                        ans = max(ans, i);
                }
            }
            for (ll i = 1; i <= k; ++i)
                printf("%lld%c", i == k ? n - ans * f[k - 1] : ans * i, i == k ? '\n' : ' ');
        }
    }
    return 0;
}