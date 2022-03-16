// InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define REG register
#define FREAD 1

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
    char ch = nc();
    int sum = 0;
    while (!(ch >= '0' && ch <= '9'))
        ch = nc();
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}
#endif

ll a[maxn];
ll sum;

int main()
{
    int T = 1, n, ans = 0;
    T = _read();
    while (T--)
    {
        sum = ans = 0;
        n = _read();
        for (int i = 1; i <= n; ++i)
        {
            a[i] = _read();
            sum = sum + a[i];
        }
        sort(a + 1, a + 1 + n);
        if (sum == 0)
            ans = 0;
        else if (2ll * a[n] > sum+1)
            ans = a[n]-sum+a[n];
        else
            ans = 1;
        printf("%d\n", ans);
    }
    return 0;
}