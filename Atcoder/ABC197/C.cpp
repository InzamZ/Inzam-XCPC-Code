#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
using ll = long long;
const ll LINF = 10000000000;

ll s[maxn];

int main()
{
    ll ans = LINF, xored, ored, bound, n;
    scanf("%lld", &n);
    bound = 1 << (n - 1);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &s[i]);
    for (int i = 0; i < bound; ++i) {
        xored = 0;
        ored = 0;
        for (int j = 0; j <= n; j++) {
            if (j < n)
                ored |= s[j];
            if (j == n || ((i >> j) & 1))
                xored ^= ored, ored = 0;
        }
        ans = min(xored, ans);
    }
    printf("%lld\n", ans);
    return 0;
}