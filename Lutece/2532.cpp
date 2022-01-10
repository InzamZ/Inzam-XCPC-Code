#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;

struct node {
    int val, ls, rs;
} Tree[maxn << 5];

int a[maxn], rt[maxn];
int tot = 1;
int kth, x, y, ans = 0, all;

int build(int l, int r)
{
    int now = tot++;
    if (l >= r) {
        Tree[now].val = 0;
        return now;
    }
    int mid = (l + r) >> 1;
    Tree[now].ls = build(l, mid);
    Tree[now].rs = build(mid + 1, r);
    Tree[now].val = 0;
    return now;
}

void query(int x, int y, int l, int r)
{
    //cout<<' '<<xver.l <<' '<< xver.r<<' '<<k<<endl;
    //cout<<' '<<xver.val <<' '<< yver.val<<' '<<k<<endl;
    //cout<<endl;
    if (l == r) {
        if (Tree[y].val - Tree[x].val > ans)
            ans = Tree[y].val - Tree[x].val;
        //cout<<ans<<' '<<Tree[y].val <<' '<< Tree[y].val<<' '<<endl;
        return ;
    }
    int mid = (l + r) >> 1;
    if (Tree[Tree[y].ls].val - Tree[Tree[x].ls].val > all / 2)
        query(Tree[x].ls, Tree[y].ls, l, mid );
    if (Tree[Tree[y].rs].val - Tree[Tree[x].rs].val > all / 2)
        query(Tree[x].rs, Tree[y].rs, mid + 1, r);
}

int update(int pre, int l, int r)
{
    int now = tot++;
    Tree[now].ls = Tree[pre].ls;
    Tree[now].rs = Tree[pre].rs;
    Tree[now].val = Tree[pre].val;
    if (l == r ) {
        ++Tree[now].val;
        //cout<<now<<' '<<Tree[now].l<<' '<<Tree[now].r<<' '<<Tree[now].val<<endl;
        return now;
    }
    int mid = (l + r) >> 1;
    if (mid >= kth)
        Tree[now].ls = update(Tree[now].ls, l, mid);
    else
        Tree[now].rs = update(Tree[now].rs, mid + 1, r);
    Tree[now].val = Tree[Tree[now].ls].val + Tree[Tree[now].rs].val;
    //cout<<now<<' '<<Tree[now].l<<' '<<Tree[now].r<<' '<<Tree[now].val<<endl;
    return now;
}

int read()
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

void print(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

int main()
{
    int N, M;
    N = read();
    M = read();
    rt[0] = build(1, N);
    for (int i = 1; i <= N; ++i) {
        kth = read();
        rt[i] = update(rt[i - 1], 1, N);
    }
    for (int i = 1; i <= M; ++i) {
        x = read();
        y = read();
        ans = 0;
        all = y - x + 1;
        query(rt[x - 1], rt[y], 1, N);
        //cout<<ans<<' '<<all<<endl;
        if (ans * 2 <= all) {
            putchar('1');
            putchar('\n');
            continue;
        }
        ans = ans * 2 - all;
        print(ans);
        putchar('\n');
    }
    return 0;
}