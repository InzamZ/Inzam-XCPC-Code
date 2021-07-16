#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;

const int maxn = 1e4 + 5;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

int main()
{
    int T = 1, n;
    ll c, s;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld", &c, &s);
        ll res = s / c;
        ll cnt = s % c;
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