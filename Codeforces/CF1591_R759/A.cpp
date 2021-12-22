//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
#define FREAD 1

const int maxn = 1e3 + 10;
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

int a[maxn];

int main()
{
    int T = 1, n, ans = 0;
    T = _read();
    while (T--) {
        ans = 1;
        bool flag = 0;
        n = _read();
        for (int i = 1; i <= n; ++i) {
            a[i] = _read();
            if (i != 1 && a[i] == 0 && a[i - 1] == 0)
                flag = 1;
            if (a[i] == 1 && a[i - 1] == 1 )
                ans += 5;
            else if (a[i] == 1)
                ans += 1;
        }
        if (flag)
            printf("%d\n", -1);
        else
            printf("%d\n", ans);
    }
    return 0;
}