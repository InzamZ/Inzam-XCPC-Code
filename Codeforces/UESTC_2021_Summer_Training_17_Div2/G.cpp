//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
//#define FREAD 1

const int maxn = 1e6 + 10;
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

struct node {
    ll x, y;
} a[maxn];

bool cmp(node a, node b)
{
    return a.y < b.y;
}

int main()
{
    ll n, T, hot = 0, cold = 0, cnt1 = 0, cnt2 = 0;
    long double ans = 0;
    scanf("%lld %lld", &n, &T);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i].x);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i].y);
        a[i].y -= T;
        if (a[i].y < 0) {
            cold += a[i].x;
            cnt1 += a[i].x * a[i].y;
        }
        if (a[i].y == 0)
            ans += a[i].x;
        if (a[i].y > 0) {
            hot += a[i].x;
            cnt2 += a[i].x * a[i].y;
        }
    }
    sort(a + 1, a + 1 + n, cmp);
    long double res = 0;
    if (abs(cnt1) == abs(cnt2))
        ans += (hot + cold);
    else if (abs(cnt1) > abs(cnt2)) {
        int i = 1;
        ans += hot;
        for (i = 1; a[i].y < 0; ++i) ;
        for (i = i - 1; i >= 1; --i) {
            if (res - a[i].x * a[i].y >= cnt2) {
                ans += ((long double)cnt2 - res) / (-a[i].y);
                break;
            }
            res -= a[i].x * a[i].y;
            ans += a[i].x;
        }
    }
    else {
        int i = 1;
        ans += cold;
        for (i = 1; a[i].y <= 0; ++i) ;
        for (i; i <= n ; ++i) {
            if (res + a[i].x * a[i].y >= (-cnt1)) {
                ans += ((long double)(-cnt1) - res) / (a[i].y);
                break;
            }
            res += a[i].x * a[i].y;
            ans += a[i].x;
        }
    }
    printf("%.20Lf\n", ans);
    return 0;
}