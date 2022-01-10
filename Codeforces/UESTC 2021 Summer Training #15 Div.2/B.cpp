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
inline int _read()
{
    char ch = nc(); int sum = 0;
    while (!(ch >= '0' && ch <= '9'))
        ch = nc();
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}
#endif
// int gcd(int x, int y)
// {
//     return y == 0 ? x : gcd(y, x % y);
// }
ll T = 1, n, ans = 0, m, x, y, t;
bool check(int ans)
{
    ll res = y * m + n - x * ans;
    return res >= y;
}
int main()
{
    scanf("%lld", &T);
    while (T--) {
        ans = 0;
        t = 0;
        scanf("%lld %lld %lld %lld", &n, &m, &x, &y);
        if (x <= y)
            printf("%lld\n", m);
        else {
            ll l = 1, r = m + 1, mid;
            while (l + 1 < r) {
                mid = (l + r) >> 1;
                if (check(mid))
                    l = mid;
                else
                    r = mid;
            }
            printf("%lld\n", l);
        }
    }
    return 0;
}