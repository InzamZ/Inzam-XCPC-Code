//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
//#define FREAD 1

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


int main()
{
    int T = 1;
    ll W, H, x1, x2, y1, y2;
    ll w1, w2, h1, h2;
    long double ans;
    scanf("%d", &T);
    while (T--) {
        bool flag = false;
        ans = 1e18;
        scanf("%lld %lld", &W, &H);
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        w1 = abs(x1 - x2); h1 = abs(y1 - y2);
        scanf("%lld %lld", &w2, &h2);
        if (w2 > W || h2 > H) {
            flag = 1;
            ans = -1;
        }
        else if (w2 > W - w1 && h2 > H - h1) {
            flag = 1;
            ans = -1;
        }
        if (x1 >= w2 || y1 >= h2 || W - x2 > w2 || H - y2 > h2)
            ans = 0;
        if (w1 + w2 <= W) {
            ans = min(ans, (long double)(abs(w2 - x1)));
            ans = min(ans, (long double)(abs((W - w2) - x2)));
        }
        if (h1 + h2 <= H) {
            ans = min(ans, (long double)(abs(h2 - y1)));
            ans = min(ans, (long double)(abs((H - h2) - y2)));
        }
        if (flag)
            printf("-1\n");
        else
            printf("%.20Lf\n", ans);
    }
    return 0;
}