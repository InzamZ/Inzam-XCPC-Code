#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int maxn = 2e5 + 5;
const int maxb = 30;
const ll inf = 1e10;

ll a[maxn];
int  L[maxn << 5], R[maxn << 5], son[maxn << 5][2];
int tot = 1;

void insert(int rt, int id, int bi)
{
    if (bi < 0)
        return ;
    if (!L[rt])
        L[rt] = id;
    R[rt] = id;
    int w = (a[id] >> bi) & 1;
    if (!son[rt][w])
        son[rt][w] = ++tot;
    insert(son[rt][w], id, bi - 1);
}

ll query(int rt, int id, int depth)
{
    if (depth < 0)
        return 0;
    int w = (a[id] >> depth) & 1;
    if (son[rt][w])
        return query(son[rt][w], id, depth - 1);
    else
        return query(son[rt][w ^ 1], id, depth - 1) + (1ll << depth);
}

ll dfs(int rt, int depth)
{
    if (depth < 0)
        return 0;
    if (son[rt][0] && son[rt][1]) {
        ll ans = inf;
        for (int i = L[son[rt][0]]; i <= R[son[rt][0]]; ++i)
            ans = min(ans, query(son[rt][1], i, depth - 1) + (1ll << depth));
        return dfs(son[rt][0], depth - 1) + dfs(son[rt][1], depth - 1) + ans;
    }
    else if (son[rt][0])
        return dfs(son[rt][0], depth - 1);
    else if (son[rt][1])
        return dfs(son[rt][1], depth - 1);
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        insert(1, i, maxb);
    printf("%lld\n", dfs(1, maxb));
    return 0;
}
