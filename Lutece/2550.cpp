#include <bits/stdc++.h>
using namespace std;

const double a = 0.65;
const int maxn = 1e5 + 10;
int n, q, c, t, cur, xl, xr, yl, yr;
int rt, d[maxn], ls[maxn], rs[maxn], g[maxn], L[maxn], R[maxn], U[maxn], D[maxn], siz[maxn], sum[maxn], cnt[maxn][15];

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

struct node {
    int x, y, v;
} s[maxn];

bool cmp1 (int a, int b)
{
    return s[a].x < s[b].x;
}
bool cmp2 (int a, int b)
{
    return s[a].y < s[b].y;
}

void maintain(int x)
{
    siz[x] = siz[ls[x]] + siz[rs[x]] + 1;
    sum[x] = sum[ls[x]] + sum[rs[x]] + s[x].v;
    for (int i = 0; i <= c; ++i)
        cnt[x][i] = 0;
    cnt[x][s[x].v] = 1;
    L[x] = R[x] = s[x].x;
    U[x] = D[x] = s[x].y;
    if (ls[x]) {
        L[x] = min(L[x], L[ls[x]]);
        R[x] = max(R[x], R[ls[x]]);
        D[x] = min(D[x], D[ls[x]]);
        U[x] = max(U[x], U[ls[x]]);
        for (int i = 0; i <= c; ++i)
            cnt[x][i] += cnt[ls[x]][i];
    }
    if (rs[x]) {
        L[x] = min(L[x], L[rs[x]]);
        R[x] = max(R[x], R[rs[x]]);
        D[x] = min(D[x], D[rs[x]]);
        U[x] = max(U[x], U[rs[x]]);
        for (int i = 0; i <= c; ++i)
            cnt[x][i] += cnt[rs[x]][i];
    }
}

bool bad(int x)
{
    return a * siz[x] < max(siz[ls[x]], siz[rs[x]]);
}

void print(int x)
{
    if (!x)
        return ;
    print(ls[x]);
    g[++cur] = x;
    print(rs[x]);
}

int build(int l, int r)
{
    if (l > r)
        return 0;
    int mid = (l + r) >> 1;
    double av1 = 0, av2 = 0, sa1 = 0, sa2 = 0;
    for (int i = l; i <= r; i++) {
        av1 += s[i].x;
        av2 += s[i].y;
    }
    av1 /= (r - l + 1);
    av2 /= (r - l + 1);
    for (int i = 1; i <= l; ++i) {
        sa1 += (s[i].x - av1) * (s[i].x - av1);
        sa2 += (s[i].y - av2) * (s[i].y - av2);
    }
    if (sa1 > sa2) {
        d[g[mid]] = 1;
        nth_element(g + l, g + mid, g + r + 1, cmp1);
    }
    else {
        d[g[mid]] = 2;
        nth_element(g + l, g + mid, g + r + 1, cmp2);
    }
    ls[g[mid]] = build(l, mid - 1);
    rs[g[mid]] = build(mid + 1, r);
    maintain(g[mid]);
    return g[mid];
}

void rebuild(int &x)
{
    cur = 0;
    print(x);
    x = build(1, cur);
    return ;
}

void insert(int &x, int v)
{
    if (!x) {
        x = v;
        maintain(x);
        return ;
    }
    if (d[x] == 1) {
        if (s[x].x > s[v].x)
            insert(ls[x], v);
        else
            insert(rs[x], v);
    }
    else {
        if (s[x].y > s[v].y)
            insert(ls[x], v);
        else
            insert(rs[x], v);
    }
    maintain(x);
    if (bad(x))
        rebuild(x);
}

int query(int x)
{
    if (!x || xr < L[x] || R[x] < xl || yr < D[x] || U[x] < yl)
        return 0;
    if (xl <= L[x] && R[x] <= xr && yl <= D[x] && U[x] <= yr ) {
        int res = 0;
        for (int i = 0; i <= c; ++i)
            res += (cnt[x][i] * ((i + t) % c));
        return res;
    }
    int res = 0;
    if (xl <= s[x].x && s[x].x <= xr && yl <= s[x].y && s[x].y <= yr )
        res = res + (s[x].v + t) % c;
    return res + query(ls[x]) + query(rs[x]);
}

int main()
{
    n = _read();
    q = _read();
    c = _read();
    ++c;
    for (int i = 1; i <= n; ++i) {
        s[i].x = _read();
        s[i].y = _read(), s[i].v = _read();
        insert(rt, i);
        //printf("%d\n",rt);
    }
    for (int i = 1; i <= q; ++i) {
        t = _read();
        xl = _read();
        yl = _read();
        xr = _read();
        yr = _read();
        t %= c;
        if (xl > xr)
            swap(xl, xr);
        if (yl > yr)
            swap(yl, yr);
        //printf("Query:%d t=%d xl=%d yl=%d xr=%d yr=%d\n",i,t,xl,yl,xr,yr);
        printf("%d\n", query(rt));
    }
    return 0;
}

