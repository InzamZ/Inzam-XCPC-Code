#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e5 + 10;
const int maxb = 510;
const int inf = 1e9;
const ll Inf = 1e18;

bool flag = false;
int T = 1, n, m, a, b;
int s[maxb], indeg[maxb];
bool imap[maxb][maxb];

bool toposort(int x)
{
    memcpy(s, indeg, sizeof(indeg));
    int num = 0;
    queue<int>q;
    --s[x];
    for (int i = 1; i <= n; ++i)
        if (!s[i])
            ++num, q.push(i);
    while (!q.empty()) {
        int res = q.front(); q.pop();
        for (int i = 1; i <= n; ++i)
            if (imap[res][i])
                if (!(--s[i]))
                    ++num, q.push(i);
    }
    return num == n;
}

int main()
{
    // scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= m; ++i) {
            scanf("%d %d", &a, &b);
            imap[a][b] = 1;
            ++indeg[b];
        }
        for (int i = 1; !flag && i <= n; ++i)
            flag = toposort(i);
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}