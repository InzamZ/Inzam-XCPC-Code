//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
// #define FREAD 1

const int maxn = 5e3 + 10;
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
int T = 1, n, ans = 1, cnt = 0;

struct node {
    int id, val;
} a[maxn], b[maxn];
int cnt1[maxn], cnt2[maxn], no[maxn], ta[maxn];
int len;
vector<int>q1[maxn];
vector<int>q2[maxn];
vector<int>wai;

ll lowbit(ll x)
{
    return x & (-x);
}

void update(ll i, ll val)
{
    ll x = i;
    while (i <= n) {
        ta[i] += val;
        i += lowbit(i);
    }
}

ll getsum(ll i)
{
    ll res = 0, x = i;
    while (i > 0) {
        res += ta[i];
        i -= lowbit(i);
    }
    return res;
}

bool countit()
{
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res += getsum(no[i]);
        update(no[i], 1);
    }
    res = n * (n - 1) / 2 - res;
    return res % 2 == 0;
}

bool dfs(int dep)
{
    if (dep >= len)
        return countit();
    int x = wai[dep];
    do {
        for (int i = 0; i < q1[x].size(); ++i)
            no[q1[x][i]] = q2[x][i];
        if (dfs(dep + 1))
            return true;
    }
    while (next_permutation(q2[x].begin(), q2[x].end()));
    return false;
}

int main()
{
    // T=_read();
    while (T--) {
        scanf("%d ", &n);
        for (int i = 1; i <= n; ++i) {
            a[i].id = i;
            scanf("%d", &a[i].val);
            ++cnt1[a[i].val];
        }
        for (int i = 1; i <= n; ++i) {
            b[i].id = i;
            scanf("%d", &b[i].val);
            ++cnt2[b[i].val];
            q2[b[i].val].push_back(i);
        }
        for (int i = 1; i <= n; ++i) {
            if (cnt1[i] != cnt2[i]) {
                ans = 0;
                break;
            }
        }
        if (ans) {
            for (int i = 1; i <= n; ++i)
                if (cnt1[a[i].val] == 1 )
                    no[i] = q2[a[i].val][0];
                else {
                    q1[a[i].val].push_back(i);
                    wai.push_back(a[i].val);
                }
            len = wai.size();
            ans = dfs(0);
        }
        printf("%s\n", !ans ? "No" : "Yes");
    }
    return 0;
}