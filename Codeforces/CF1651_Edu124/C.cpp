//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
#define FREAD 1

const int maxn = 2e5 + 10;
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
inline ll _read()
{
    char ch = nc(); ll sum = 0;
    while (!(ch >= '0' && ch <= '9'))
        ch = nc();
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}
#endif

ll r1[maxn], r2[maxn];

int main()
{
    int T = 1, n;
    ll cnt1, cnt2, cnt3, ans = 0;
    T = _read();
    while (T--) {
        n = _read();
        for (int i = 1; i <= n; ++i)
            r1[i] = _read();
        for (int i = 1; i <= n; ++i)
            r2[i] = _read();
        ll r1l = abs(r1[1] - r2[1]), r1r = abs(r1[n] - r2[1]), r2l = abs(r2[1] - r1[1]), r2r = abs(r2[n] - r1[1]);
        ans = abs(r1[1] - r2[n]) + abs(r1[n] - r2[1]);
        ans = min(ans, abs(r1[1] - r2[1]) + abs(r1[n] - r2[n]));
        for (int i = 1; i <= n; ++i) {
            r1l = min(abs(r1[1] - r2[i]), r1l);
            r1r = min(abs(r1[n] - r2[i]), r1r);
            r2l = min(abs(r2[1] - r1[i]), r2l);
            r2r = min(abs(r2[n] - r1[i]), r2r);
        }
        ans = min(ans, abs(r1[1] - r2[1]) + r1r + r2r);
        ans = min(ans, abs(r1[1] - r2[n]) + r1r + r2l);
        ans = min(ans, abs(r1[n] - r2[1]) + r1l + r2r);
        ans = min(ans, abs(r1[n] - r2[n]) + r1l + r2l);
        ans = min(ans, r1l + r1r + r2l + r2r);
        printf("%lld\n", ans);
    }
    return 0;
}