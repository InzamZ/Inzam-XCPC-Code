//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
// #define FREAD 1

const int maxn = 1e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 1e9 + 7;

#ifdef FREAD
inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline ll _read()
{
    char ch = nc(); ll sum = 0;
    while (!(ch >= '0' && ch <= '9'))
        ch = nc();
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}
#endif

multiset<ll>q;

int main()
{
    ll T = 1, n, ans = 0, op, x, k;
    // T=_read();
    while (T--) {
        ans = 0;
        scanf("%lld", &n);
        q.clear();
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &op);
            scanf("%lld", &x);
            if (op == 1)
                q.insert(x);
            else {
                bool flag = 0;
                scanf("%lld", &k);
                if (op == 2) {
                    auto it = q.upper_bound(x);
                    for (int i = 0; i < k ; ++i) {
                        if (it == q.begin()) {
                            flag = 1;
                            break;
                        }
                        --it;
                    }
                    if (flag)
                        printf("-1\n");
                    else
                        printf("%lld\n", *it);
                }
                else {
                    auto it = q.lower_bound(x);
                    for (int i = 1; i < k && it != q.end(); ++i) {
                        ++it;
                    }
                    if (it == q.end())
                        printf("-1\n");
                    else
                        printf("%lld\n", *it);
                }
            }
        }
    }
    return 0;
}