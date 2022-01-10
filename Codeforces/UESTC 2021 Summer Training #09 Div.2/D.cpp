// freopen("data.in", "r", stdin);
// freopen("yours.out", "w", stdout);
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
using ll = long long;

struct node {
    int val, l, r;
    int ls, rs;
} Tree[maxn << 5];

int a[maxn], rt[maxn];
int tot = 0;
int ver, op, kth, x, y;
vector<int>b;

inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read()
{
    char ch = nc(); int sum = 0;
    while (!(ch >= '0' && ch <= '9'))
        ch = nc();
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}

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
    if (k >= yver.val)
        return -1;
    // cout<<' '<<xver.l <<' '<< xver.r<<' '<<k<<endl;
    // cout<<' '<<xver.val <<' '<< yver.val<<' '<<k<<endl;
    if (xver.l == xver.r)
        return yver.val - xver.val > k ? xver.l : -1;
    int mid = (xver.l + xver.r) >> 1, res;
    res = query(xver.ls, yver.ls, k);
    if (res != -1)
        return res;
    res = query(xver.rs, yver.rs, k);
    if ( res != -1)
        return res;
    else
        return -1;
}

inline int update(int pre)
{
    int now = tot++;
    Tree[now].l = Tree[pre].l;
    Tree[now].r = Tree[pre].r;
    Tree[now].ls = Tree[pre].ls;
    Tree[now].rs = Tree[pre].rs;
    Tree[now].val = Tree[pre].val;
    //cout<<now<<' '<<Tree[now].l<<' '<<Tree[now].r<<' '<<Tree[now].val<<endl;
    if (Tree[now].l == Tree[now].r ) {
        ++Tree[now].val;
        return now;
    }
    int mid = (Tree[now].l + Tree[now].r) >> 1;
    if (kth <= mid)
        Tree[now].ls = update(Tree[now].ls);
    else
        Tree[now].rs = update(Tree[now].rs);
    Tree[now].val = max(Tree[Tree[now].ls].val, Tree[Tree[now].rs].val);
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
    // freopen("data.in", "r", stdin);
    // freopen("yours.out", "w", stdout);
    int N, M, K;
    N = read();
    M = read();
    for (int i = 1; i <= N; ++i)
        a[i] = read();
    rt[0] = build(1, N);
    for (int i = 1; i <= N; ++i) {
        kth = a[i];
        rt[i] = update(rt[i - 1]);
    }
    for (int i = 1; i <= M; ++i) {
        x = read();
        y = read();
        kth = read();
        kth = (y - x + 1) / kth;
        int ans = query(rt[x - 1], rt[y], kth);
        cout << ans << endl;
    }
    return 0;
}