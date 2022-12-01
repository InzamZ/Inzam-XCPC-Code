#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e6 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

ll ans[maxn][2], a[maxn], b[maxn];

int main()
{
    int T = 1, n;
    // scanf("%d",&T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%lld", &a[i]);
        for (int i = 1; i <= n; ++i)
            scanf("%lld", &b[i]);
        ans[1][0] = a[1];
        ans[1][1] = b[1];
        for (int i = 2; i <= n; ++i) {
            ans[i][0] = max(ans[i - 1][0], ans[i - 1][1] + a[i]);
            ans[i][1] = max(ans[i - 1][1], ans[i - 1][0] + b[i]);
        }
        printf("%lld\n", max(ans[n][1], ans[n][0]));
    }
    return 0;
}