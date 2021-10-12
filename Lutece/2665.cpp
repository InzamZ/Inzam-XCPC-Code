#include <bits/stdc++.h>
using namespace std;
using ll = __int128;

const int maxn = 2e5 + 10;
const ll mod = 998244353;

struct point {
    ll x, y;
    int quad;
    point () : x(1), y(1), quad(1) {}
    point (long long a, long long b) : x(a), y(b)
    {
        if (a > 0 && b >= 0)
            quad = 1;
        if (a <= 0 && b > 0)
            quad = 2;
        if (a < 0 && b <= 0)
            quad = 3;
        if (a >= 0 && b < 0)
            quad = 4;
    }
    point (int a, int b) : x(a), y(b)
    {
        if (a > 0 && b >= 0)
            quad = 1;
        if (a <= 0 && b > 0)
            quad = 2;
        if (a < 0 && b <= 0)
            quad = 3;
        if (a >= 0 && b < 0)
            quad = 4;
    }
    bool cross(const point a)
    {
        __int128 temp1 = x * a.y - y * a.x;
        return temp1 > 0 ;
    }

    bool collinear (const point a)
    {
        __int128 temp1 = x * a.y - y * a.x;
        return quad == a.quad ? temp1 == 0 : false;
    }

    bool operator < (const point a)
    {
        return quad == a.quad ? cross(a) > 0 : quad < a.quad;
    }
} b[maxn];

ll len(point a, point c)
{
    return (((a.x - c.x) % mod ) * ((a.x - c.x) % mod) % mod + ((a.y - c.y) % mod) * ((a.y - c.y) % mod) % mod) % mod;
}

ll unmodlen(point a, point c)
{
    return (a.x - c.x) * (a.x - c.x) + (a.y - c.y)  * (a.y - c.y) ;
}

ll mabs(ll x)
{
    return x >= 0 ? x : -x;
}

vector<point>a;
int cnt = 0;

int main()
{
    int T = 1, n;
    long long x, y;
    ll ans = 0;
    // scanf("%d", &T);
    while (T--) {
        // ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld %lld", &x, &y);
            a.push_back(point(x, y));
        }
        sort(a.begin(), a.end());
        b[++cnt] = a[0];
        for (int i = 1; i < n; ++i) {
            if (!a[i].collinear(b[cnt]))
                b[++cnt] = a[i];
            else
                b[cnt] = (mabs(a[i].x) > mabs(b[cnt].x) || mabs(a[i].y) > mabs(b[cnt].y)) ? a[i] : b[cnt];
        }
        for (int i = 2; i <= cnt; ++i) {
            ans += len(b[i], b[i - 1]);
            ans %= mod;
        }
        ans += len(b[1], b[cnt]);
        ans %= mod;
        printf("%lld\n", (long long)((ans + mod) % mod));
    }
    return 0;
}