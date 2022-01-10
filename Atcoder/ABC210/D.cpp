#include <bits/stdc++.h>
using namespace std;
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;
#define pii pair<int,int>
#define pdd pair<double,double>

const double pi = acos(-1.0);
const ll inf = 1e18;
const int maxn = 1010;
ll a[maxn][maxn], dp[maxn][maxn], f[maxn][maxn];

int T = 1, h, w, cur = 0;
ll ans = 1e18, c;

int main()
{
    while (T--) {
        scanf("%d %d %lld", &h, &w, &c);
        for (int i = 0; i <= h; ++i)
            dp[i][0] = inf;
        for (int j = 0; j <= w; ++j)
            dp[0][j] = inf;
        for (int i = 0; i <= h; ++i)
            for (int j = 0; j <= w; ++j)
                f[i][j] = inf;
        for (int i = 1; i <= h; ++i)
            for (int j = 1; j <= w; ++j)
                scanf("%lld", &a[i][j]);
        for (int i = 1; i <= h; ++i)
            for (int j = 1; j <= w; ++j)
                dp[i][j] = min(a[i][j], min(dp[i - 1][j], dp[i][j - 1]) + c);
        for (int i = 1; i <= h; ++i)
            for (int j = 1; j <= w; ++j)
                f[i][j] = a[i][j] + c + min(dp[i - 1][j], dp[i][j - 1]);
        for (int i = 1; i <= h; ++i)
            for (int j = 1; j <= w; ++j)
                ans = min(ans, f[i][j]);
        //considering S is on the right side of T
        for (int i = 1; i <= h; ++i)
            for (int j = 1; j < w + 1 - j; ++j)
                swap(a[i][j], a[i][w + 1 - j]);
        for (int i = 0; i <= h; ++i)
            dp[i][0] = inf;
        for (int j = 0; j <= w; ++j)
            dp[0][j] = inf;
        for (int i = 0; i <= h; ++i)
            for (int j = 0; j <= w; ++j)
                f[i][j] = inf;
        for (int i = 1; i <= h; ++i)
            for (int j = 1; j <= w; ++j)
                dp[i][j] = min(a[i][j], min(dp[i - 1][j], dp[i][j - 1]) + c);
        for (int i = 1; i <= h; ++i)
            for (int j = 1; j <= w; ++j)
                f[i][j] = a[i][j] + c + min(dp[i - 1][j], dp[i][j - 1]);
        for (int i = 1; i <= h; ++i)
            for (int j = 1; j <= w; ++j)
                ans = min(ans, f[i][j]);
        printf("%lld\n", ans);
        return 0;
    }
}