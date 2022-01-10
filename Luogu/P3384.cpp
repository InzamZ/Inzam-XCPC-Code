#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define M 200200
#define mem(a,b) memset(a,b,sizeof(a))
#define mid (r+l)/2
#define lson 2*root
#define rson 2*root+1
int m, n, p, r, res = 0;
//链式前向星
int to[M], from[M], first[M], inext[M], w1[M], w2[M];
int id[M], fa[M], top[M], siz[M], son[M], cur = 0, dep[M];
//线段树
int val[M << 1], mark[M << 1];
int ans = 0, tot = 0;
void add(int a, int b)
{
    ++tot;
    from[tot] = a;
    to[tot] = b;
    inext[tot] = first[a];
    first[a] = tot;
    ++tot;
    from[tot] = b;
    to[tot] = a;
    inext[tot] = first[b];
    first[b] = tot;
    return ;
}
//-------------------线段树------------------------------
void build (int root, int l, int r)
{
    mark[root] = 0;
    if (l == r) {
        val[root] = w2[l] % p;
        return ;
    }
    build(lson, l, mid);
    build(rson, mid + 1, r);
    val[root] = (val[lson] + val[rson]) % p;
}

void pushdown(int root, int l, int r)
{
    val[lson] += (mark[root] * (mid - l + 1));
    val[rson] += (mark[root] * (r - mid));
    mark[lson] += mark[root];
    mark[rson] += mark[root];
    mark[lson] %= p;
    mark[rson] %= p;
    mark[root] = 0;
    return ;
}

void update(int root, int l, int r, int astart, int aend, int k)
{
    if (astart <= l && r <= aend) {
        mark[root] += k;
        val[root] += k * (r - l + 1);
    }
    else {
        if (mark[root])
            pushdown(root, l, r);
        if (astart <= mid)
            update(lson, l, mid, astart, aend, k);
        if (aend > mid)
            update(rson, mid + 1, r, astart, aend, k);
        val[root] = (val[lson] + val[rson]) % p;
    }
}
void addval(int x, int y, int k)
{
    k %= p;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        update(1, 1, n, id[top[x]], id[x], k); //跳到链首，求值
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    update(1, 1, n, id[x], id[y], k);
}

inline void query(int root, int l, int r, int fl, int fr)
{
    if (fl <= l && r <= fr) {
        res += val[root];
        res %= p;
        return ;
    }
    else {
        if (mark[root])
            pushdown(root, l, r);
        if (fl <= mid)
            query(lson, l, mid, fl, fr);
        if (fr > mid)
            query(rson, mid + 1, r, fl, fr);
    }
}
//-------------------线段树------------------------------
//---------------树链剖分预处理--------------------------
void dfs1(int x, int f, int d)
{
    fa[x] = f;
    siz[x] = 1;
    dep[x] = d;
    int maxson = -1;
    for (int i = first[x]; i; i = inext[i]) {
        if (to[i] == f)
            continue;
        dfs1(to[i], x, d + 1);
        siz[x] += siz[to[i]];
        if (siz[to[i]] > maxson)
            maxson = siz[to[i]], son[x] = to[i];
    }
}

void dfs2(int x, int topf)
{
    id[x] = ++cur;
    top[x] = topf;
    w2[cur] = w1[x];
    if (!son[x])
        return ;
    dfs2(son[x], topf);
    for (int i = first[x]; i; i = inext[i]) {
        if (to[i] != fa[x] && to[i] != son[x])
            dfs2(to[i], to[i]);
    }
}
//---------------树链剖分预处理--------------------------
int lss(int beg, int end)
{
    int ans = 0;
    while (top[beg] != top[end]) {
        if (dep[top[beg]] < dep[top[end]])
            swap(beg, end);
        res = 0;
        query(1, 1, n, id[top[beg]], id[beg]);
        ans += res;
        ans %= p;
        beg = fa[top[beg]];
    }
    if (dep[beg] > dep[end])
        swap(beg, end);
    res = 0;
    query(1, 1, n, id[beg], id[end]);
    ans += res;
    return ans %= p;
}
int main()
{
    scanf ("%d %d %d %d", &n, &m, &r, &p);
    for (int i = 1; i <= n; i++)
        scanf ("%d", &w1[i]);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf ("%d %d", &a, &b);
        add(a, b);
    }
    dfs1(r, 0, 1);
    dfs2(r, r);
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int opt;
        scanf ("%d", &opt);
        switch (opt) {
        case 1: {
            int a, b, c;
            scanf ("%d %d %d", &a, &b, &c);
            addval(a, b, c);
            break;
        }
        case 2: {
            int a, b;
            scanf ("%d %d", &a, &b);
            res = 0;
            printf("%d\n", lss(a, b) % p);
            break;
        }
        case 3: {
            int a, b;
            scanf ("%d %d", &a, &b);
            update(1, 1, n, id[a], id[a] + siz[a] - 1, b);
            break;
        }
        case 4: {
            int a;
            scanf ("%d", &a);
            res = 0;
            query(1, 1, n, id[a], id[a] + siz[a] - 1);
            printf("%d\n", res);
            break;
        }
        }
    }
    return 0;
}