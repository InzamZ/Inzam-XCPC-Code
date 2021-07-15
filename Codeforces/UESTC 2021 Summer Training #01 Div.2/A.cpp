#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 2e5 + 5;

ll gcd(ll x, ll y)
{
    return y == 0 ? x : gcd(y, x % y);
}
ll a[maxn], b[maxn], ans;
int main()
{
    int T = 1, n, m;
    // scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i)
            scanf("%lld", &a[i]);
        for (int i = 2; i <= n; ++i) {
            if (i == 2)
                ans = abs(a[2] - a[1]);
            else
                ans = gcd(ans, abs(a[i] - a[1]));
        }
        for (int i = 1; i <= m; ++i) {
            scanf("%lld", &b[i]);
            printf("%lld%c", gcd(b[i] + a[1], ans), i == m ? '\n' : ' ');
        }
    }
    return 0;
}