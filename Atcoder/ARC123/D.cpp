#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 2e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

ll a[maxn], b[maxn], c[maxn], q[maxn * 2];

int main()
{
    int T = 1, n;
    // scanf("%d",&T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
            if (i != 1 ) {
                b[i] = b[i - 1]; c[i] = c[i - 1];
                if (a[i] - a[i - 1] > 0)
                    b[i] += (a[i] - a[i - 1]);
                if (a[i] - a[i - 1] < 0)
                    c[i] -= (a[i] - a[i - 1]);
                q[++q[0]] = b[i];
                q[++q[0]] = c[i];
            }
            else {
                b[i] = a[i];
                q[++q[0]] = b[i];
                q[++q[0]] = c[i];
            }
        }
        sort(q + 1, q + 1 + q[0]);
        ll x = q[(1 + q[0]) >> 1], ans = 0;
        for (int i = 1; i <= q[0]; ++i)
            ans += abs(x - q[i]);
        printf("%lld\n",  ans);
    }
    return 0;
}