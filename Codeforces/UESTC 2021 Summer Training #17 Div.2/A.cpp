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

ll p[maxn][2];

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
    ll cross(const point a)
    {
        ll temp1 = x * a.y - y * a.x;
        return temp1 ;
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

    ll mod ()
    {
        return x * x + y * y;
    }
} ;

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

vector<point>v;

int main()
{
    int T = 1;
    int n, res = 0, len = 0;
    // scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld %lld", &p[i][0], &p[i][1]);
            if (i != 1) {
                p[i][0] -= p[1][0];
                p[i][1] -= p[1][1];
            }
            if (i == 1)
                v.push_back(point(0, 0));
            else
                v.push_back(point(p[i][0], p[i][1]));
        }
        sort(v.begin() + 1, v.end());
        len = v.size();
        if ( n % 2 == 1)
            printf("No\n");
        else {
            for (int i = 0; i <= len / 2; ++i) {
                point l1 = point(v[i].x - v[i + 1].x, v[i].y - v[i + 1].y);
                point l2 = point(v[(i + len / 2) % len].x - v[(i + 1 + len / 2) % len].x, v[(i + len / 2) % len].y - v[(i + 1 + len / 2) % len].y);
                if (l1.cross(l2) != 0 || l1.mod() != l2.mod()) {
                    printf("No\n");
                    return 0;
                }
            }
            printf("YES\n");
        }
    }
    return 0;
}