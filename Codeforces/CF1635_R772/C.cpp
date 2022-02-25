//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
// #define FREAD 1

const int maxn = 5000 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 1e9 + 7;
ll a[maxn], k;
vector<ll>v[maxn];

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
    scanf("%d", &T);
    while (T--) {
        scanf("%d %lld", &n, &k);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
            v[1].push_back(a[i]);
        }
        sort(v[1].begin(), v[1].end());
        for (int i = 2; i <= n; ++i) {
            ll cur = 0;
            for (int j = 1; j <= i; ++j)
                cur += a[j];
            v[i].push_back(cur);
            for (int j = i + 1; j <= n; ++j) {
                cur -= a[j - i];
                cur += a[j];
                v[i].push_back(cur);
            }
            sort(v[i].begin(), v[i].end());
        }
        for (int i = 0; i <= n; ++i) {
            ll ans = 0;
            for (int j = 1; j <= n; ++j)
                ans = max(ans, (*(v[j].end() - 1)) + k * min(i, j));
            printf("%lld", ans);
            if (i == n)
                printf("\n");
            else
                printf(" ");
        }
        for (int i = 0; i <= n; ++i)
            v[i].clear();
    }
    return 0;
}