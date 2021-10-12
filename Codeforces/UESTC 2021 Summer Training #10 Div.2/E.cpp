// freopen("data.in", "r", stdin);
// freopen("yours.out", "w", stdout);
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
ll mx = 1e18, k = -1;
int T = 1, n, ans = 0, m;

int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}

void check(ll x)
{
    ll t = ceil(double(n) / x) * x - n;
    if ((n + t) * (m + t) / x < mx) {
        mx = (n + t) * (m + t) / x;
        k = t;
    }
    if ((n + t) * (m + t) / x == mx)
        k = min(t, k);
}

int main()
{
    // freopen("data.in", "r", stdin);
    // freopen("yours.out", "w", stdout);
    // scanf("%d",&T);
    while (T--) {
        ans = 0;
        scanf("%d %d", &m, &n);
        if (m > n)
            swap(m, n);
        if (gcd(m, n) == m)
            printf("0\n");
        else if (n - m == 1)
            printf("0\n");
        else if (m == 1)
            printf("0\n");
        else {
            ans = n - m;
            for (int i = 1; i * i <= ans; ++i) {
                if (ans % i == 0) {
                    check(i);
                    check(ans / i);
                }
            }
            printf("%lld\n", k);
        }
    }
    return 0;
}