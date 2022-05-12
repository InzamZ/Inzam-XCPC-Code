#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
using ll = long long;

struct node {
    int val, l, r;
    int ls, rs;
} Tree[maxn * 20];

int a[maxn], rt[maxn * 2];
int tot = 0;
int ver, op, loc, val;


inline int build(int l, int r)
{
    int now = tot++;
    Tree[now].l = l;
    Tree[now].r = r;
    if (l == r) {
        Tree[now].val = a[l];
        return now;
    }
    int mid = (l + r) >> 1;
    Tree[now].ls = build(l, mid);
    Tree[now].rs = build(mid + 1, r);
    return now;
}

inline int query(int root)
{
    node now = Tree[root];
    if (now.l == now.r)
        return now.val;
    int mid = (now.l + now.r) >> 1;
    if (loc <= mid)
        return query(now.ls);
    else
        return query(now.rs);
}

inline int update(int pre)
{
    int now = tot++;
    Tree[now].l = Tree[pre].l;
    Tree[now].r = Tree[pre].r;
    Tree[now].ls = Tree[pre].ls;
    Tree[now].rs = Tree[pre].rs;
    if (Tree[now].l == Tree[now].r ) {
        Tree[now].val = val;
        return now;
    }
    int mid = (Tree[now].l + Tree[now].r) >> 1;
    if (loc <= mid)
        Tree[now].ls = update(Tree[now].ls);
    else
        Tree[now].rs = update(Tree[now].rs);
    return now;
}
inline int read(){
    int X = 0;
    bool flag = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            flag = 0;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        X = (X << 1) + (X << 3) + ch - '0';
        ch = getchar();
    }
    if (flag)
        return X;
    return ~(X - 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    N = read();
    M = read();
    for (int i = 1; i <= N; ++i)
        a[i] = read();
    rt[0] = build(1, N);
    for (int i = 1; i <= M; ++i) {
        ver = read();
        op = read();
        loc = read();
        if (op == 2) {
            rt[i] = tot++;
            Tree[rt[i]].l = Tree[rt[ver]].l;
            Tree[rt[i]].r = Tree[rt[ver]].r;
            Tree[rt[i]].ls = Tree[rt[ver]].ls;
            Tree[rt[i]].rs = Tree[rt[ver]].rs;
            cout << query(rt[ver]) << endl;
        }
        else {
            val = read();
            rt[i] = update(rt[ver]);
        }
    }
    return 0;
}