#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
using ll = long long;

struct node {
    int val, l, r;
    int ls, rs;
} Tree[maxn << 6];

int a[maxn], b[maxn], rta[maxn], rtb[maxn], ida[maxn], idb[maxn];
int tot = 0;
int ver, op, kth;
vector<int>x, y;

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

inline bool query(int ra, int rb)
{
    node xver = Tree[ra], yver = Tree[rb];
    bool ok = true;
    if (xver.l == xver.r)
        if (xver.val == yver.val)
            return true;
        else
            return false;
    ok &= query(xver.ls, yver.ls);
    ok &= query(xver.rs, yver.rs);
    return ok;
}

inline int update(int pre, int id)
{
    int now = tot++;
    Tree[now].l = Tree[pre].l;
    Tree[now].r = Tree[pre].r;
    Tree[now].ls = Tree[pre].ls;
    Tree[now].rs = Tree[pre].rs;
    Tree[now].val = Tree[pre].val;
    //cout<<now<<' '<<Tree[now].l<<' '<<Tree[now].r<<' '<<Tree[now].val<<endl;
    if (Tree[now].l == Tree[now].r) {
        Tree[now].val = 1;
        return now;
    }
    int mid = (Tree[now].l + Tree[now].r) >> 1;
    if (id <= mid) {
        Tree[now].ls = update(Tree[now].ls, id);
    }
    else {
        Tree[now].rs = update(Tree[now].rs, id);
    }
    return now;
}

int getid(vector<int> &ve, int x)
{
    return lower_bound(ve.begin(), ve.end(), x) - ve.begin() + 1;
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
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int N, M, K;
    N = read();
    for (int i = 1; i <= N; ++i) {
        a[i] = read();
        x.push_back(a[i]);
    }
    for (int i = 1; i <= N; ++i) {
        b[i] = read();
        y.push_back(b[i]);
    }
    sort(x.begin(), x.end());
    x.erase((x.begin(), x.end()), x.end());
    sort(y.begin(), y.end());
    y.erase((y.begin(), y.end()), y.end());
    for (int i = 1; i <= x.size(); ++i) {
        ida[i] = getid(x, a[i]);
        idb[i] = getid(y, b[i]);
    }
    rta[0] = build(1, x.size());
    rtb[0] = build(1, y.size());
    for (int i = 1; i <= N; ++i)
        rta[i] = update(rta[i - 1], ida[i]);
    for (int i = 1; i <= N; ++i)
        rtb[i] = update(rtb[i - 1], idb[i]);
    M = read();
    for (int i = 1; i <= M; ++i) {
        int qa, qb;
        qa = read();
        qb = read();
        if (query(rta[qa], rtb[qb]))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}