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


int main()
{
    int T = 1;
    ll n, k, ans = 0;
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%lld%lld", &n, &k);
        if (k == 1)
            printf("%lld", n);
        else
            while (n) {
                ans += (n % k);
                n -= (n % k);
                if (n) {
                    ans++;
                    n /= k;
                }
            }
        printf("%lld\n", ans);
    }
    return 0;
}