//InzamZ
//
#include <cstdio>
#include <algorithm>
using namespace std;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
#define FREAD 1

const int maxn = 1e5 + 10;

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

int to[maxn];
bool vis[maxn];

int dfs(int cur, int rt)
{
    if (cur == rt)
        return 0;
    vis[cur] = 1;
    dfs(to[cur], rt);
    return 0;
}

int main()
{
    int T = 1, n, ans = 0;
    // T=_read();
    // freopen("8.in","r",stdin);
    while (T--) {
        ans = 0;
        n = _read();
        for (int i = 1; i <= n; ++i)
            to[i] = _read();
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                ans++;
                dfs(to[i], i);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}