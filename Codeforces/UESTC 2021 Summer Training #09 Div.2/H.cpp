#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 2e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

ll ans[maxn][2];
ll a[maxn];

int main()
{
    int T = 1, n;
    // scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%lld", &a[i]);
        for (int i = 1; i <= n; ++i) {
            if (i == 1) {
                ans[i][0] = abs(a[1] - a[2]);
                ans[i][1] = abs(a[1] - a[n]);
            }
            else if (i == n) {
                ans[i][0] = abs(a[n] - a[n - 1]);
                ans[i][1] = abs(a[1] - a[n]);
            }
            else {
                ans[i][0] = min(abs(a[i] - a[i + 1]), abs(a[i] - a[i - 1]));
                ans[i][1] = max(abs(a[i] - a[1]), abs(a[i] - a[n]));
            }
            printf("%lld %lld\n", ans[i][0], ans[i][1]);
        }
    }
    return 0;
}