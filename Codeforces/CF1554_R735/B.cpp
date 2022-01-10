//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
// #define FREAD 1

const int maxn = 100 + 10;
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

ll a[maxn];
int cnt[maxn];
ll dp[maxn][maxb];
vector<int>q;

const long double pi = acos(-1.0);

int bitcnt(ll x)
{
    int ans = 0;
    while (x) {
        if (x & 1ll)
            ++ans;
        x >>= 1;
    }
    return ans;
}

int main()
{
    ll T = 1;
    int b, n;
    // scanf("%lld", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
            cnt[i] = bitcnt(a[i]);
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
            cnt[i] = bitcnt(a[i]);
        }
    }
    return 0;
}