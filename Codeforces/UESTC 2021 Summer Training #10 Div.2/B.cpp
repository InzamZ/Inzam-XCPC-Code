#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

// inline char nc()
// {
//     static char buf[100000], *p1 = buf, *p2 = buf;
//     return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
// }
// inline int read()
// {
//     char ch = nc(); int sum = 0;
//     while (!(ch >= '0' && ch <= '9'))
//         ch = nc();
//     while (ch >= '0' && ch <= '9')
//         sum = sum * 10 + ch - 48, ch = nc();
//     return sum;
// }

const int maxn = 1e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

long double len(long double x, long double y, long double x2, long double y2)
{
    return (x - x2) * (x - x2) + (y - y2) * (y - y2);
}

int main()
{
    int T = 1;
    ll a, b, c, d, r;
    // scanf("%d", &T);
    while (T--) {
        // ans = 0;
        scanf("%lld %lld %lld %lld %lld", &r, &a, &b, &c, &d);
        long double ansr = (sqrt(len(a, b, c, d)*1.0) + r ) / 2.0, ansx, ansy;
        ansr = min(ansr, r);
        if (len(a, b, c, d) == 0)
            ansx = c + ansr / 2.0;
        else if (len(a, b, c, d) >= r * r)
            ansx = a;
        else
            ansx = c + (a - c) * ansr / sqrtf128(len(a, b, c, d)*1.0);
        if (len(a, b, c, d) == 0)
            ansy = d;
        else if (len(a, b, c, d) >= r * r)
            ansy = b;
        else
            ansy = d + (b - d) * ansr / sqrt(len(a, b, c, d)*1.0);
        printf("%.16Lf %.16Lf %.16Lf\n", ansx, ansy, ansr);
    }
    return 0;
}