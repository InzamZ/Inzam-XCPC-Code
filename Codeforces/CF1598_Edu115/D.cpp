//Author: InzamZ

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define IF(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define DF(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 2e5 + 10;
const int maxb = 10;
const int inf = 1e9;
const ll Inf = 1e18;

bool flag = true;
int T = 1, n, len;
ll a[maxn], b[maxn], ans = 0;
int cnta[maxn], cntb[maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ans = 1ll * n * (n - 1) * (n - 2) / 6;
        IF(i, 1, n) {
            cnta[i] = cntb[i] = 0;
        }
        IF(i, 1, n) {
            scanf("%lld %lld", &a[i], &b[i]);
            ++cnta[a[i]];
            ++cntb[b[i]];
        }
        IF(i, 1, n) {
            ans -= max(0ll, 1ll * (cnta[a[i]] - 1) * (cntb[b[i]] - 1));
            // --cnta[a[i]];
            // --cntb[b[i]];
        }
        printf("%lld\n", ans);
    }
    return 0;
}