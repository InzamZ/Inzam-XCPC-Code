#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e6 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

// inline char nc()
// {
//     static char buf[100000], *p1 = buf, *p2 = buf;
//     return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
// }
// inline int read()
// {
//     char ch = nc(); int sum = 0;
//     while (!(ch >= '0' && ch <= '9'))
//         ch = nc();
//     while (ch >= '0' && ch <= '9')
//         sum = sum * 10 + ch - 48, ch = nc();
//     return sum;
// }

bool vis[maxn];
int  m, n, cnt[maxn], a[maxn], b[maxn], id[maxn];
vector<int>ans;

int check(int k)
{
    int cntt = 0;
    queue<int>q;
    for (int i = 1; i <= n; ++i)
        vis[i] = 0;
    for (int i = 1; i <= n; ++i) {
        if (b[i] != k && vis[i] == false) {
            ++cntt;
            q.push(i);
            while (!q.empty()) {
                int res = q.front(); q.pop();
                vis[res] = 1;
                res = res - k;
                if (res <= 0)
                    res += n;
                if (vis[id[res]] == 0)
                    q.push(id[res]);
            }
        }
    }
    return n - cnt[k] - cntt;
}

int main()
{
    int T = 1, n;
    scanf("%d", &T);
    while (T--) {
        ans.clear();
        scanf("%d %d", &n, &m);
        for (int i = 0; i <= n; ++i)
            cnt[i] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            id[a[i]] = i;
            b[i] = (i - a[i] + n);
            if (b[i] < 0)
                b[i] += n;
            ++cnt[b[i]];
        }
        for (int i = 0; i < n; ++i) {
            if (n - cnt[i] - (n - cnt[i]) / 2 > m)
                continue;
            if (check(i) <= m)
                ans.push_back(i);
        }
        printf("%ld", ans.size());
        for (int i = 0; i < ans.size(); ++i)
            printf(" %d", ans[i]);
        putchar('\n');
    }
    return 0;
}