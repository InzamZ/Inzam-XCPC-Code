#include <cstdio>
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;
#define M 200200
#define inf 1000000
#define mem(a,b) memset(a,b,sizeof(a))
#define mid (r+l)/2
#define lson 2*root
#define rson 2*root+1
using ll = long long;
int m, n, p, r, res = 1;
//链式前向星
int to[M], from[M], first[M], inext[M];
int id[M], tails[M], cur = 0;
//线段树
int sum[M << 2], rt[M];
ll color[M << 2], mark[M << 2];
int ans = 0, tot = 0, cnt = 0;
inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int _read()
{
    char ch = nc();
    int sum = 0;
    while (!(ch >= '0' && ch <= '9'))
        ch = nc();
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}
void add(int a, int b)
{
    ++tot;
    from[tot] = a;
    to[tot] = b;
    inext[tot] = first[a];
    first[a] = tot;/*
    ++tot;
    from[tot] = b;
    to[tot] = a;
    inext[tot] = first[b];
    first[b] = tot;*/
    return ;
}

int cmpcol(ll a, ll b)
{
    int cnt = 0;
    a ^= b;
    while (a) {
        if (a & 1ll)
            ++cnt;
        a >>= 1;
    }
    return cnt;
}
//-------------------线段树------------------------------
void build (int root, int l, int r)
{
    mark[root] = 0;
    if (l == r) {
        sum[root] = 1;
        color[root] = 1;
        return ;
    }
    build(lson, l, mid);
    build(rson, mid + 1, r);
    color[root] = 1;
    sum[root] = 1 ;
}

void pushdown(int root, int l, int r)
{
    sum[lson] = 1;
    sum[rson] = 1;
    color[lson] = mark[root];
    color[rson] = mark[root];
    mark[lson] = mark[root];
    mark[rson] = mark[root];
    mark[root] = 0;
    return ;
}

void update(int root, int l, int r, int astart, int aend, ll k)
{
    if (astart <= l && r <= aend) {
        mark[root] = k;
        sum[root] = 1;
        color[root] = k;
    }
    else {
        if (mark[root])
            pushdown(root, l, r);
        if (astart <= mid && k ^ color[lson])
            update(lson, l, mid, astart, aend, k);
        if (aend > mid && k ^ color[rson])
            update(rson, mid + 1, r, astart, aend, k);
        color[root] = color[lson] | color[rson];
        sum[root] = sum[rson] + cmpcol(color[root], color[rson]) ;
    }
}

inline int qsum(int root, int l, int r, int fl, int fr, ll &col)
{
    int ans = 0;
    if (fl <= l && r <= fr) {
        ans = cmpcol(col, color[root] | col);
        col = col | color[root];
        return ans;
    }
    else {
        if (mark[root])
            pushdown(root, l, r);
        if (fl <= mid && col ^ color[lson])
            ans += qsum(lson, l, mid, fl, fr, col);
        if (fr > mid && col ^ color[rson])
            ans += qsum(rson, mid + 1, r, fl, fr, col);
    }
    return ans;
}

void dfs1(int x, int f)
{
    id[x] = ++cur;
    for (int i = first[x]; i; i = inext[i]) {
        if (to[i] == f)
            continue;
        dfs1(to[i], x);
    }
    tails[id[x]] = cur;
}

int main()
{
    n = _read();
    m = _read();
    for (int i = 1; i <= n; i++) {
        int a;
        a = _read();
        if (a == 0)
            rt[cnt++] = i;
        add(a, i);
    }
    for (int i = 0; i < cnt; ++i)
        dfs1(rt[i], -1);
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int opt;
        opt = _read();
        r = _read();
        switch (opt) {
        case 1: {
            p = _read();
            ll tem = 1;
            update(1, 1, n, id[r], tails[id[r]], tem << (p % 51));
            break;
        }
        case 2: {
            ll tem = 0;
            //printf("%d %d %d\n",id[r], tails[id[r]],tem);
            printf("%d\n", qsum(1, 1, n, id[r], tails[id[r]], tem));
            break;
        }
        }
    }
    return 0;
}