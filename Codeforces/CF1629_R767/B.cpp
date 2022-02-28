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
    int T = 1, l, r, k, ans = 0;
    T = _read();
    while (T--) {
        l = _read();
        r = _read();
        k = _read();
        if (l % 2 == 0 && r % 2 == 0)
            ans = (r - l) / 2;
        if (l % 2 != 0 && r % 2 != 0)
            ans = (r - l) / 2 + 1;
        if (l % 2 != 0 && r % 2 == 0)
            ans = (r - l) / 2 + 1;
        if (l % 2 == 0 && r % 2 != 0)
            ans = (r - l) / 2 + 1;
        if (l == r && r > 1)
            printf("YES\n");
        else
            printf("%s\n", k >= ans ? "YES" : "NO");
    }
    return 0;
}