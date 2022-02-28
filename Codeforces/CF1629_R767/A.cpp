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
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 1e9 + 7;

struct node {
    int a, b;
} s[maxn];

bool cmp(node a, node b)
{
    return a.a == b.a ? a.b < b.b : a.a < b.a;
}

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
    int T = 1, n, ans = 0;
    T = _read();
    while (T--) {
        ans = 0;
        n = _read();
        ans = _read();
        for (int i = 1; i <= n; ++i)
            s[i].a = _read();
        for (int i = 1; i <= n; ++i)
            s[i].b = _read();
        sort(s + 1, s + 1 + n, cmp);
        int i = 1;
        while (i <= n && ans >= s[i].a) {
            ans += s[i].b;
            ++i;
        }
        printf("%d\n", ans);
    }
    return 0;
}