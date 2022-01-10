#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define maxn 600010

int son[maxn][2], siz[maxn], datas[maxn], num[maxn];
int root[maxn], id[maxn], tails = 0;

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

void rotate(int &rt, int k)
{
    int nrt = son[rt][!k]; //new root
    son[rt][!k] = son[nrt][k];
    son[nrt][k] = rt;
    siz[nrt] = siz[rt];
    siz[rt] = siz[son[rt][0]] + siz[son[rt][1]] + 1;
    rt = nrt;
}

void maintain(int &rt, bool k)
{
    if (siz[son[son[rt][k]][k]] > siz[son[rt][!k]])
        rotate(son[rt][k], !k);
    else if (siz[son[son[rt][k]][!k]] > siz[son[rt][!k]])
        rotate(son[rt][k], k), rotate(rt, !k);
    else
        return ;
    maintain(son[rt][0], 0);
    maintain(son[rt][1], 1);
    maintain(rt, 0);
    maintain(rt, 1);
}

void insert(int &rt, int val, int ids)
{
    if (rt == 0) {
        rt = ++tails;
        datas[rt] = val;
        son[rt][0] = son[rt][1] = 0;
        siz[rt] = 1;
        id[rt] = ids;
        return ;
    }
    ++siz[rt];
    if (val <= datas[rt])
        insert(son[rt][0], val, ids);
    else
        insert(son[rt][1], val, ids);
    maintain(rt, datas[rt] > val);
}

int xth(int rt, int x)
{
    int cur = rt;
    while (siz[son[cur][0]] + 1 != x) {
        if (siz[son[cur][0]] + 1 < x)
            x -= (siz[son[cur][0]] + 1), cur = son[cur][1];
        else
            cur = son[cur][0];
    }
    return id[cur];
}

int f[maxn];

int ifind(int x)
{
    return f[x] == x ? x : (f[x] = ifind(f[x]));
}

void imerge(int x, int y)
{
    f[ifind(x)] = ifind(y);
}

void dfs(int &rt, int &_to)
{
    if (!rt) return ;
    f[id[rt]] = id[_to];
    insert(_to, datas[rt], id[rt]);
    if (son[rt][0])
        dfs(son[rt][0], _to);
    if (son[rt][1])
        dfs(son[rt][1], _to);
}

void Merge(int &a, int &b)
{
    if (siz[a] > siz[b])
        swap(a, b);
    dfs(a, b);
    a = b;
}

int main()
{
    int n, m, a, b, q;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &num[i]);
        f[i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d", &a, &b);
        a=ifind(a);b=ifind(b);
        imerge(a, b);
    }
    for (int i = 1; i <= n; i++)
        insert(root[f[i] = ifind(i)], num[i], i);
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i) {
        char op[3];
        scanf("%s %d %d", op, &a, &b);
        if (op[0] == 'Q') {
            if (b > siz[root[ifind(a)]])
                printf("-1\n");
            else
                printf("%d\n", xth(root[f[a] = ifind(a)], b));
        }
        else {
            int &p = root[ifind(a)];
            int &q = root[ifind(b)];
            if (p != q)
                Merge(p, q);
        }
    }
    return 0;
}