//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
#define FREAD 1

const int maxn = 1050;
const int maxb = 1e6;
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

int vis[maxn];
int a, b, fa[maxn], cnt[maxn];

int ifind(int x)
{
    return fa[x] == x ? x : (fa[x] = ifind(fa[x]));
}

void imerge(int x, int y)
{
    --vis[cnt[ifind(x)]];
    --vis[cnt[ifind(y)]];
    cnt[ifind(y)] += cnt[ifind(x)];
    fa[ifind(x)] = ifind(y);
    ++vis[cnt[ifind(y)]];
}

int main()
{
    int T = 1, n, ans = 0, d = 0;
    // T = _read();
    while (T--) {
        ans = 1;
        n = _read();
        d = _read();
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
            cnt[i] = 1;
        }
        vis[1] = n;
        for (int i = 1; i <= d; ++i) {
            a = _read();
            b = _read();
            if (ifind(a) != ifind(b))
                imerge(a, b);
            else
                ++ans;
            int res = 0;
            for (int k = n, j = ans; k >= 1 && j; --k) {
                if (vis[k] == 0)
                    continue;
                if (vis[k] >= j) {
                    res += (j * k);
                    j = 0;
                    break;
                }
                j -= vis[k];
                res += (k * vis[k]);
            }
            // for (int k = 1; k <= n; ++k)
            //     printf("%d%c", vis[k], k == n ? '\n' : ' ');
            printf("%d\n", res - 1);
        }
    }
    return 0;
}