#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;
using ll = long long;
struct node {
    int val;
    node *l, *r;
} s[maxn];
node *head[2];
int n, m, a, deb = 0;

void move_to_r(int x, int y, bool flag);

void move_to_l(int x, int y, bool flag)
{
    if (flag) {
        move_to_r(x, y, !flag);
        return ;
    }
    s[x].l->r = s[x].r;
    s[x].r->l = s[x].l;
    s[x].l = s[y].l;
    s[x].r = &s[y];
    s[y].l->r = &s[x];
    s[y].l = &s[x];
}

void move_to_r(int x, int y, bool flag)
{
    if (flag) {
        move_to_l(x, y, !flag);
        return ;
    }
    s[x].l->r = s[x].r;
    s[x].r->l = s[x].l;
    s[x].l = &s[y];
    s[x].r = s[y].r;
    s[y].r->l = &s[x];
    s[y].r = &s[x];
}

void swap_xy(int x, int y)
{
    node *xl = s[x].l, *xr = s[x].r;
    if (xr == &s[y]) {//交换相邻元素
        s[x].l->r=&s[y];
        s[y].r->l=&s[x];
        s[x].r = s[y].r;
        s[y].l = s[x].l;
        s[x].l = &s[y];
        s[y].r = &s[x];
        return ;
    }
    if (xl == &s[y]) {
        s[x].r->l=&s[y];
        s[y].l->r=&s[x];
        s[y].r = s[x].r;
        s[x].l = s[y].l;
        s[y].l = &s[x];
        s[x].r = &s[y];
        return ;
    }
    s[x].l->r = &s[y];
    s[x].r->l = &s[y];
    s[x].l = s[y].l;
    s[x].r = s[y].r;
    s[y].l->r = &s[x];
    s[y].r->l = &s[x];
    s[y].l = xl;
    s[y].r = xr;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    bool flag = 0;
    cin >> n >> m;
    node *pre = &s[0];
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        s[a].l = pre;
        s[a].r = &s[n + 1];
        s[a].val = a;
        pre->r = &s[a];
        pre = &s[a];
        if (i == 1)
            s[0].r = &s[a];
        if (i == n)
            s[n + 1].l = &s[a];
    }
    head[0] = &s[0];
    head[1] = &s[n + 1];
    for (int i = 1; i <= m; ++i) {
        int op, x, y;
        cin >> op;
        if (op == 4)
            flag = !flag;
        else {
            cin >> x >> y;
            if (op == 1 )
                move_to_r(x, y, flag);
            if (op == 2 )
                move_to_l(x, y, flag);
            if (op == 3)
                swap_xy(x, y);
        }
    }
    node *cur = head[flag];
    if (flag)
        cur = cur->l;
    else
        cur = cur->r;
    while ( cur != nullptr && cur != head[!flag]) {
        cout << cur->val << ' ';
        if (flag)
            cur = cur->l;
        else
            cur = cur->r;
    }
    cout << '\n';
    return 0;
}