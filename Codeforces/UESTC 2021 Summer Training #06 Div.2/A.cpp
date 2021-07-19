#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e5;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

int main()
{
    int T = 1, n;
    ll ans = 0, a, m;
    // scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            ans = 0, m;
            scanf("%lld", &m);
            a = m;
            while (a) {
                ans += (a % 10);
                a /= 10;
            }
            printf("%lld\n", ans * m);
        }
    }
    return 0;
}