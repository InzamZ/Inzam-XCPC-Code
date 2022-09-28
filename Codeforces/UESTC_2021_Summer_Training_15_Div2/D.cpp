//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
// #define FREAD 1

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

int fa[100010];
bool ap[100010];

int ifind(int x)
{
    return fa[x] == x ? x : (fa[x] = ifind(fa[x]));
}

void imerge(int x, int y)
{
    fa[ifind(x)] = ifind(y);
}

ll F[maxn], deg[maxn];
vector<pii>e;

bool cmp(pii a, pii b)
{
    return b.second == a.second ? a.first < b.first : a.second < b.second;
}

int main()
{
    int T = 1, n, ans = 0, m, u, v;
    // scanf("%d",&T);
    while (T--) {
        ans = 0;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= m; ++i) {
            scanf("%d %d", &u, &v);
            if (u > v)
                swap(u, v);
            if (u != v)
                e.push_back(pii(u, v));
        }
        sort(e.begin(), e.end(), cmp);
        for (int i = 1; i <= n; ++i)
            fa[i] = i;
        for (int i = 0; i < e.size(); ++i) {
            if (ifind(e[i].first) != ifind(e[i].second)) {
                imerge(e[i].first, e[i].second);
                deg[e[i].first]++;
                deg[e[i].second]++;
            }
        }
        for (int i = 1; i <= n; ++i)
            deg[0] = max(deg[0], deg[i]);
        printf("%lld\n", deg[0]);
    }
    return 0;
}