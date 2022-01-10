#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int T = 1;
    ll c, sum;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld", &c, &sum);
        ll res = sum / c;
        ll cnt = sum % c;
        ll ans = 0;
        for (int i = 1; i <= c; i++) {
            if (i <= cnt)
                ans += ((res + 1) * (res + 1));
            else
                ans += ((res) * (res));
        }
        printf("%lld\n", ans);
    }
    return 0;
}