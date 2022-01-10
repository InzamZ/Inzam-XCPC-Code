//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
// #define FREAD 1

const int maxn = 1e6 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 1e9 + 7;

ll a[maxn];
char s[maxn];
priority_queue< ll, vector<ll>, less<ll> > e[30];

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

int main()
{
    int T = 1, n, k;
    ll ans = 0;
    // T = _read();
    while (T--) {
        ans = 0;
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; ++i)
            scanf("%lld", &a[i]);
        scanf("%s", s);
        for (int i = 1; i <= n; ++i) {
            e[s[i - 1] - 'a'].push(a[i]);
            if (s[i - 1] != s[i]) {
                for (int j = 1; j <= k && !e[s[i - 1] - 'a'].empty(); ++j) {
                    ll res = e[s[i - 1] - 'a'].top();
                    ans += res;
                    e[s[i - 1] - 'a'].pop();
                }
                while (!e[s[i - 1] - 'a'].empty())
                    e[s[i - 1] - 'a'].pop();
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}