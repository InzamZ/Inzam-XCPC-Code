//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
#define FREAD 1

const int maxn = 1e5 + 10;
const int maxb = 1e4;
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

struct A {
    int val, bval;
    int id;
} a[maxn];

struct B {
    int val, aval;
    int id;
} b[maxn];

bool Acmp (A x, A y)
{
    if (x.val == y.val)
        return x.id > y.id;
    return x.val > y.val;
}

bool Bcmp (B x, B y)
{
    if (x.val == y.val)
        return x.id > y.id;
    return x.val > y.val;
}

bool vis[maxn];

int main()
{
    int T = 1, n;
    T = _read();
    while (T--) {
        n = _read();
        for (int i = 1; i <= n; ++i) {
            a[i].val = _read();
            b[i].aval = a[i].val;
            a[i].id = i;
        }
        for (int i = 1; i <= n; ++i) {
            b[i].val = _read();
            a[i].bval = b[i].val;
            b[i].id = i;
        }
        sort(a + 1, a + 1 + n, Acmp);
        sort(b + 1, b + 1 + n, Bcmp);
        int pb = 1, pa = 1;
        int numa = b[1].aval, numb = a[1].bval;
        while (1) {
            bool flag = 1;
            for (pb; b[pb].val >= numb && pb <= n; ++pb) {
                vis[b[pb].id] = 1;
                numa = min(numa, b[pb].aval);
                flag = 0;
            }
            for (pa; a[pa].val >= numa && pa <= n; ++pa) {
                vis[a[pa].id] = 1;
                numb = min(numb, a[pa].bval);
                flag = 0;
            }
            if (flag)
                break;
        }
        for (int i = 1; i <= n; ++i) {
            printf("%d", vis[i] ? 1 : 0);
            vis[i] = 0;
        }
        putchar('\n');
    }
    return 0;
}