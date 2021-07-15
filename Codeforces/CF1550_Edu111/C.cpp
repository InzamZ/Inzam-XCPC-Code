#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;
const int maxn = 1e6 + 5;
const int maxb = 110;
const int inf = 1e9 + 7;
const ll Inf = 1e18;

int a[maxn];

int main()
{
    int T = 1, n, mx1, mx2, mn1, mn2;
    ll ans = 0;
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        ans = n + n - 1;
        for (int i = 1; i <= n - 2; ++i) {
            if (a[i] <= a[i + 1] && a[i + 1] <= a[i + 2])
                continue;
            if (a[i] >= a[i + 1] && a[i + 1] >= a[i + 2])
                continue;
            ans++;
        }
        for (int i = 1; i <= n - 3; ++i) {
            if (a[i] <= a[i + 1] && a[i + 1] <= a[i + 2])
                continue;
            if (a[i] <= a[i + 1] && a[i + 1] <= a[i + 3])
                continue;
            if (a[i] <= a[i + 2] && a[i + 2] <= a[i + 3])
                continue;
            if (a[i + 1] <= a[i + 2] && a[i + 2] <= a[i + 3])
                continue;
            if (a[i] >= a[i + 1] && a[i + 1] >= a[i + 2])
                continue;
            if (a[i] >= a[i + 1] && a[i + 1] >= a[i + 3])
                continue;
            if (a[i] >= a[i + 2] && a[i + 2] >= a[i + 3])
                continue;
            if (a[i + 1] >= a[i + 2] && a[i + 2] >= a[i + 3])
                continue;
            ans++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}