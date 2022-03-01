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

int main()
{
    int T = 1, h, m, ans = 0;
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%d:%d", &h, &m);
        h %= 12;
        h = h * 60 + m;
        m *= 12;
        h = abs(h - m);
        if (h > 360)
            h = 720 - h;
        m = __gcd(h, 720);
        if (h == 0)
            printf("%d\n", h);
        else {
            h = h / m ;
            m = 720 / m;
            ans = __gcd(m, 360);
            if (ans == m)
                printf("%d\n", h * 360 / m);
            else {
                h = h * 360 / ans;
                m = m / ans;
                printf("%d/%d\n", h, m);
            }
        }
    }
    return 0;
}