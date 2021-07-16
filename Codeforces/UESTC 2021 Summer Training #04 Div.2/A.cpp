#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;
#define pii pair<int,int>
#define pdd pair<double,double>

const double pi = acos(-1.0);
const int maxn = 2e3 + 10;
const int inf = 1e9;
const ll Inf = 1e18;

// struct point {
//     double x, y;
// } p[maxn];

pdd p[maxn];

double w[maxn];
int cnt = 0;
int T = 1, n, a, b;

int main()
{
    scanf("%d", &n);
    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        scanf("%lf %lf", &p[i].first, &p[i].second);
    for (int i = 1; i <= n; ++i) {
        cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (j != i)
                w[++cnt] = atan2(p[j].second - p[i].second, p[j].first - p[i].first);
        }
        sort(w + 1, w + 1 + cnt);
        for (int j = 1; j <= cnt && w[j] <= 0; ++j) {
            int k = 1;
            while (w[k] - w[j] < pi && k <= cnt)
                ++k;
            ans += (1ll * (k - j - 1) * (k - j - 2) / 2) * ((cnt - k + j) * (cnt - k + j - 1) / 2);
        }
    }
    printf("%lld\n", ans);
    return 0;
}