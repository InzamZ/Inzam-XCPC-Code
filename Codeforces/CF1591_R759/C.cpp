//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
// #define FREAD 1

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

vector<int>a;
vector<int>b;

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    int T = 1, n, k;
    ll ans = 0, tmp = 0;
    scanf("%d", &T);
    while (T--) {
        bool flag = 0;
        scanf("%d %d", &n, &k);
        a.clear();
        b.clear();
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &ans);
            if (ans < 0)
                b.push_back(-ans);
            else if (ans > 0)
                a.push_back(ans);
        }
        ans = 0, tmp = 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (; !a.empty();) {
            ll cost;
            for (int i = 1; i <= k && !a.empty(); ++i) {
                if (i == 1) {
                    cost = a[a.size() - 1] * 2;
                    tmp = max(tmp, cost);
                }
                a.pop_back();
            }
            ans += cost;
        }
        for (; !b.empty();) {
            ll cost;
            for (int i = 1; i <= k && !b.empty(); ++i) {
                if (i == 1) {
                    cost = b[b.size() - 1] * 2;
                    tmp = max(tmp, cost);
                }
                b.pop_back();
            }
            ans += cost;
        }
        printf("%lld\n", ans - tmp / 2);
    }
    return 0;
}