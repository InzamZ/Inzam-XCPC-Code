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
    ll n, ans = 0;
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%lld", &n);
        ans = n / 120 * 300;
        if (n == 0)
            ans = 0;
        else if (n  <= 6 )
            ans = 15;
        else if (n % 2 == 0)
            ans = n / 2 * 5;
        else
            ans = (n + 1) / 2 * 5;
        printf("%lld\n", ans);
    }
    return 0;
}