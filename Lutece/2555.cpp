#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
using ll = long long;

struct node {
    int fa, l, r;
    int ls, rs, rank;
} Tree[maxn * 20];

int  rt[maxn * 2];
int tot = 0, Flag = 0;
int a, op, b, val;

inline void copy (int x, int y)
{
    Tree[x].l = Tree[y].l;
    Tree[x].r = Tree[y].r;
    Tree[x].ls = Tree[y].ls;
    Tree[x].rs = Tree[y].rs;
    Tree[x].fa = Tree[y].fa;
    Tree[x].rank = Tree[y].rank;
}

inline int build(int l, int r)
{
    int now = tot++;
    Tree[now].l = l;
    Tree[now].r = r;
    if (l == r) {
        Tree[now].fa = l;
        Tree[now].rank = 1;
        return now;
    }
    int mid = (l + r) >> 1;
    Tree[now].ls = build(l, mid);
    Tree[now].rs = build(mid + 1, r);
    return now;
}

inline int find(int root, int x)
{
    node now = Tree[root];
    if (now.l == now.r)
        return now.fa;
    int mid = (now.l + now.r) >> 1;
    if (x <= mid)
        return find(now.ls, x);
    else
        return find(now.rs, x);
}

inline int getfa(int root, int x)
{
    int fa = find(root, x);
    if (fa == x)
        return x;
    else
        return getfa(root, fa);
}

inline int update(const int pre, int loc, int val)
{
    int now = tot++;
    copy(now, pre);
    if (Tree[now].l == Tree[now].r ) {
        Tree[now].fa = val;
        return now;
    }
    int mid = (Tree[now].l + Tree[now].r) >> 1;
    if (loc <= mid)
        Tree[now].ls = update(Tree[now].ls, loc, val);
    else
        Tree[now].rs = update(Tree[now].rs, loc, val);
    return now;
}

inline int read()
{
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
    rt[0] = build(1, N);
    for (int i = 1; i <= M; ++i) {
        op = read();
        a = read();
        if (op == 2) {
            rt[i] = tot++;
            copy(rt[i], rt[a]);
        }
        else if (op == 1) {
            b = read();
            int fa = getfa(rt[i - 1], a);
            int fb = getfa(rt[i - 1], b);
            if (Tree[fa].rank > Tree[fb].rank)
                swap(fa, fb);
            Flag = Tree[fa].rank == Tree[fb].rank;
            Tree[fb].rank += Flag;
            rt[i] = update(rt[i - 1], fa, fb);
        }
        else  {
            b = read();
            rt[i] = tot++;
            copy(rt[i], rt[i - 1]);
            int fa = getfa(rt[i], a), fb = getfa(rt[i], b);
            if (fa == fb)
                putchar('1'), putchar('\n');
            else
                putchar('0'), putchar('\n');
        }
    }
    return 0;
}