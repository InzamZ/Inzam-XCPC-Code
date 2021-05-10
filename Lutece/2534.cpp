#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
using ll = long long;
int pos[maxn];
struct node {
    int pre, next, val;
} s[maxn];
int head[2];
int n, m, a;
//1 3 -1 -1 -1

int lowbit(int x)
{
    return x & (-x);
}

void add(int k, int val)
{
    while (k < n) {
        pos[k] += val;
        k += lowbit(k);
    }
}

int getpos(int k)
{
    int ans = 0;
    while (k > 0) {
        ans += pos[k];
        k -= lowbit(k);
    }
    return ans;
}

int move_to_l(int x, int y, bool flag)
{
    int px = getpos(x), py = getpos(y);
    int npx = y + py > px, npy = y - py > px;
    add(x, npx - px);
    add(x + 1, px - npx - npx > px);
    add(y, npy - py);
    add(y + 1, py - npy);
    s[px].next
}

int move_to_r(int x, int y, bool flag)
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    bool flag = 0;
    cin >> n >> m;
    head[0] = 1;
    head[1] = n;
    for (int i = 1; i <= n; ++i) {
        cin >> a;
        pos[a] = 1;
        s[i] = {i - 1, i + 1, a};
    }
    for (int i = 1; i <= m; ++i) {
        int op, x, y;
        cin >> op;
        if (op == 4)
            flag = !flag;
        else {
            cin >> x >> y;
            if ((op == 1 && !flag ) || (op == 2 && flag))
                move_to_l(x, y);
            if ((op == 2 && !flag) || (op == 1 && flag))
                move_to_r(x, y);
            if (op == 3)
                swap_xy(x, y);
        }
    }
    return 0;
}