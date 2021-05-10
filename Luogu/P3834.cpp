#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
using ll = long long;

struct node {
    int val, l, r;
    int ls, rs;
} Tree[maxn<<5];

int a[maxn], rt[maxn];
int tot = 0;
int ver, op, kth, x, y;
vector<int>b;

inline int build(int l, int r)
{
    int now = tot++;
    Tree[now].l = l;
    Tree[now].r = r;
    if (l == r) {
        Tree[now].val = 0;
        return now;
    }
    int mid = (l + r) >> 1;
    Tree[now].ls = build(l, mid);
    Tree[now].rs = build(mid + 1, r);
    Tree[now].val = 0;
    return now;
}

inline int query(int x, int y, int k)
{
    node xver = Tree[x], yver = Tree[y];
    // cout<<' '<<xver.l <<' '<< xver.r<<' '<<k<<endl;
    // cout<<' '<<xver.val <<' '<< yver.val<<' '<<k<<endl;
    if (xver.l == xver.r)
        return xver.l;
    int mid = (xver.l + xver.r) >> 1;
    if (Tree[yver.ls].val - Tree[xver.ls].val >= k)
        return query(xver.ls, yver.ls, k);
    else
        return query(xver.rs, yver.rs, k - (Tree[yver.ls].val - Tree[xver.ls].val));
}

inline int update(int pre)
{
    int now = tot++;
    Tree[now].l = Tree[pre].l;
    Tree[now].r = Tree[pre].r;
    Tree[now].ls = Tree[pre].ls;
    Tree[now].rs = Tree[pre].rs;
    Tree[now].val = Tree[pre].val + 1;
    //cout<<now<<' '<<Tree[now].l<<' '<<Tree[now].r<<' '<<Tree[now].val<<endl;
    if (Tree[now].l == Tree[now].r )
        return now;
    int mid = (Tree[now].l + Tree[now].r) >> 1;
    if (kth <= mid)
        Tree[now].ls = update(Tree[now].ls);
    else
        Tree[now].rs = update(Tree[now].rs);
    return now;
}

int getid(int x)
{
    return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
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
    int N, M, K;
    N = read();
    M = read();
    for (int i = 1; i <= N; ++i) {
        a[i] = read();
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    b.erase((b.begin(), b.end()),b.end());
    rt[0] = build(1, b.size());
    for (int i = 1; i <= N; ++i) {
        kth = getid(a[i]);
        //cout<<kth<<endl;
        rt[i]=update(rt[i - 1]);
    }
    for (int i = 1; i <= M; ++i) {
        x = read();
        y = read();
        kth = read();
        cout << b[query(rt[x - 1], rt[y], kth)-1] << endl;
    }
    return 0;
}