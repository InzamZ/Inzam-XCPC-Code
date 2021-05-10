
    #include<cstdio>
#include<iostream>
using namespace std;

#define maxn 1010
typedef long long ll;
ll num[maxn][maxn], k, ans;
ll n, m, qx1, qx2, qy1, qy2, tot = 1, rt = 1, q;
#define o0 (tree[o].son[0])
#define o1 (tree[o].son[1])
#define o2 (tree[o].son[2])
#define o3 (tree[o].son[3])
#define len(a,b,c,d) (((b)-(a)+1)*((d)-(c)+1))

struct node {
    ll val, lazy;
    ll son[4];
} tree[maxn * maxn * 4];

void pushup(ll o)
{
    tree[o].val = tree[o0].val + tree[o1].val + tree[o2].val + tree[o3].val;
}

inline void build(ll o, ll x1, ll x2, ll y1, ll y2)
{
    tree[o].lazy = 0;
    if (x1 == x2 && y1 == y2) {
        tree[o].val = num[x1][y1];
        return ;
    }
    ll midx = (x1 + x2) / 2, midy = (y1 + y2) / 2;
    if (y1 == y2) {
        tree[o].son[0] = ++tot;
        build(o0, x1, midx, y1, y1);
        tree[o].son[1] = ++tot;
        build(o1, midx + 1, x2, y2, y2);
    }
    else if (x1 == x2) {
        tree[o].son[0] = ++tot;
        build(o0, x1, x1, y1, midy);
        tree[o].son[2] = ++tot;
        build(o2, x1, x1, midy + 1, y2);
    }
    else {
        tree[o].son[0] = ++tot;
        build(o0, x1, midx, y1, midy);
        tree[o].son[1] = ++tot;
        build(o1, midx + 1, x2, y1, midy);
        tree[o].son[2] = ++tot;
        build(o2, x1, midx, midy + 1, y2);
        tree[o].son[3] = ++tot;
        build(o3, midx + 1, x2, midy + 1, y2);
    }
    pushup(o);
}

void pushdown(ll o, ll x1, ll x2, ll y1, ll y2)
{
    ll midx = (x1 + x2) / 2, midy = (y1 + y2) / 2;
    tree[o0].lazy += tree[o].lazy;
    tree[o1].lazy += tree[o].lazy;
    tree[o2].lazy += tree[o].lazy;
    tree[o3].lazy += tree[o].lazy;
    tree[o0].val += len(x1, midx, y1, midy) * tree[o].lazy;
    tree[o1].val += len(midx + 1, x2, y1, midy) * tree[o].lazy;
    tree[o2].val += len(x1, midx, midy + 1, y2) * tree[o].lazy;
    tree[o3].val += len(midx + 1, x2, midy + 1, y2) * tree[o].lazy;
    tree[o].lazy = 0;
}

inline ll getsum(ll o, ll x1, ll x2, ll y1, ll y2)
{
    ll res = 0;
    if (qx1 <= x1 && x2 <= qx2 && qy1 <= y1 && y2 <= qy2)
        return tree[o].val;
    pushdown(o, x1, x2, y1, y2);
    ll midx = (x1 + x2) / 2, midy = (y1 + y2) / 2;
    if (midx >= qx1 && midy >= qy1)
        res += getsum(o0, x1, midx, y1, midy);
    if (midx < qx2 && midy >= qy1)
        res += getsum(o1, midx + 1, x2, y1, midy);
    if (midx >= qx1 && midy < qy2)
        res += getsum(o2, x1, midx, midy+1, y2);
    if (midx < qx2 && midy < qy2)
        res += getsum(o3, midx + 1, x2, midy + 1, y2);
    return res;
}

inline void addval(ll o, ll x1, ll x2, ll y1, ll y2)
{
    if (qx1 <= x1 && x2 <= qx2 && qy1 <= y1 && y2 <= qy2) {
        tree[o].val += k * len(x1, x2, y1, y2);
        tree[o].lazy += k;
        return ;
    }
    pushdown(o, x1, x2, y1, y2);
    ll midx = (x1 + x2) / 2, midy = (y1 + y2) / 2;
    if (midx >= qx1 && midy >= qy1)
        addval(o0, x1, midx, y1, midy);
    if (midx < qx2 && midy >= qy1)
        addval(o1, midx + 1, x2, y1, midy);
    if (midx >= qx1 && midy < qy2)
        addval(o2, x1, midx, midy+1, y2);
    if (midx < qx2 && midy < qy2)
        addval(o3, midx + 1, x2, midy + 1, y2);
    pushup(o);
}
template <class T>
inline void Read(T &Ret)
{
    char ch;
    int flg = 1;
    while (ch = getchar(), ch < '0' || ch > '9')
        if (ch == '-')
            flg = -1;
    Ret = ch - '0';
    while (ch = getchar(), ch >= '0' && ch <= '9')
        Ret = Ret * 10 + ch - '0';
    ungetc(ch, stdin);
    Ret *= flg;
}
int main()
{
    Read(n);
    Read(m);
    Read(q);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            Read(num[i][j]);
    build(rt, 1, n, 1, m);
    for (int i = 1; i <= q; i++) {
        ll op;
        Read(op);
        Read(qx1);
        Read(qy1);
        Read(qx2);
        Read(qy2);
        if (qx1 > qx2)
            swap(qx1, qx2);
        if (qy1 > qy2)
            swap(qy1, qy2);
        if (op == 2) {
            ans = getsum(rt, 1, n, 1, m);
            printf("%lld\n", ans);
        }
        if (op == 1) {
            Read(k);
            addval(rt, 1, n, 1, m);
        }
    }
    return 0;
}
