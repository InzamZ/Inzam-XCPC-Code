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
const ll mod = 425;

int fa[maxn], ROOT;
ll lazy[maxn], val[maxn], ans[maxn];
bool vis[maxn];
vector<int>e[maxn];

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

void pushdown(int rt)
{
    if (rt != ROOT)
        pushdown(fa[rt]);
    if (lazy[rt])
        for (int i = 0; i < e[rt].size(); ++i) {
            val[e[rt][i]] += lazy[rt];
            lazy[e[rt][i]] += lazy[rt];
            ans[e[rt][i]] += lazy[rt];
        }
    lazy[rt] = 0;
}

void pushup(int rt)
{
    if (rt != ROOT && ans[rt] > ans[fa[rt]]) {
        ans[fa[rt]] = ans[rt];
        pushup(fa[rt]);
    }
}

void add(int pos, ll v)
{
    if (pos != ROOT)
        pushdown(fa[pos]);
    lazy[pos] += v;
    val[pos] += v;
    ans[pos] += v;
    pushup(pos);
}

ll query(int pos)
{
    if (pos != ROOT)
        pushdown(fa[pos]);
    return ans[pos];
}

int main()
{
    int T = 1, n, x, y, k, op, Q;
    // T=_read();
    while (T--) {
        n = _read();
        for (int i = 1; i < n; ++i) {
            x = _read();
            y = _read();
            e[x].push_back(y);
            fa[y] = x;
        }
        for (int i = 1; i <= n; ++i)
            if (fa[i] == 0) {
                ROOT = i;
                break;
            }
        Q = _read();
        for (int i = 1; i <= Q; ++i) {
            op = _read();
            if (op == 1) {
                x = _read();
                k = _read();
                add(x, k);
            }
            else {
                x = _read();
                printf("%lld\n", query(x));
            }
        }
    }
    return 0;
}