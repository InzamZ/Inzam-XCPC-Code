#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 60;
const int maxb = 110;
const int mod = 998244353;
const ll Inf = 1e18;

ll gcd(ll x, ll y)
{
    return y == 0 ? x : gcd(y, x % y);
}

ll a[maxn], b[maxn];
bool vis[maxn];

int main()
{
    int T = 1, n, K;
    ll ans = 0;
    // scanf("%d",&T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &a[i]);
            ans = gcd(ans, a[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &b[i]);
            ans = gcd(ans, b[i]);
        }
        ll temp = 1, aa, bb;
        aa = 0, bb = 0;
        int cnt;
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i)
                if (vis[i] == 0) {
                    cnt = i;
                    break;
                }
            for (int i = 0; i < n; ++i) {
                if (!vis[i] && max(gcd(aa, a[cnt])*gcd(bb, b[cnt]), gcd(aa, b[cnt])*gcd(bb, a[cnt])) <
                        max(gcd(aa, a[i])*gcd(bb, b[i]), gcd(aa, b[i])*gcd(bb, a[i])))
                    cnt = i;
            }
            vis[cnt] = 1;
            if (gcd(aa, a[cnt])*gcd(bb, b[cnt]) > gcd(aa, b[cnt])*gcd(bb, a[cnt])) {
                aa = gcd(aa, a[cnt]);
                bb = gcd(bb, b[cnt]);
            }
            else {
                aa = gcd(aa, b[cnt]);
                bb = gcd(bb, a[cnt]);
            }
        }
        printf("%lld\n", aa * bb / ans);
    }
    return 0;
}