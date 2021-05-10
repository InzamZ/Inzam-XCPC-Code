#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
using ll = long long;

int op[maxn][3], f[maxn], _rank[maxn];
struct node {
    int t, x;
    node(int a, int b): t(a), x(b) {}
};
stack<node>s;

int ifind(int x)
{
    while (x != f[x])
        x = f[x];
    return x;
}

bool ifsame(int x, int y)
{
    return ifind(x) == ifind(y);
}

void doop1(int x, int y, int t)
{
    x = ifind(x);
    y = ifind(y);
    if (x == y)
        return ;
    if (_rank[x] > _rank[y])
        swap(x, y);
    f[x] = y;
    _rank[y] += _rank[x];
    s.push(node(t, x));
}

void doop2(int x)
{
    int cnt;
    while (!s.empty() && s.top().t >= x) {
        f[s.top().x] = s.top().x;
        s.pop();
    }
    if (s.empty())
        cnt = 1;
    else
        cnt = s.top().t + 1;
    for (int j = cnt; j <= x; ++j) {
        if (op[j][0] == 1)
            doop1(op[j][1], op[j][2], j);
        else if (op[j][0] == 2)
            doop2(op[j][1]);
    }
}

void doop3(int x, int y)
{
    if (ifsame(x, y))
        cout << 1 << endl;
    else
        cout << 0 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        f[i] = i, _rank[i] = 1;
    for (int i = 1; i <= m; ++i) {
        cin >> op[i][0];
        if (op[i][0] == 2)
            cin >> op[i][1];
        else
            cin >> op[i][1] >> op[i][2];
    }
    for (int i = 1; i <= m; ++i) {
        if (op[i][0] == 1)
            doop1(op[i][1], op[i][2], i);
        else if (op[i][0] == 2)
            doop2(op[i][1]);
        else if (op[i][0] == 3)
            doop3(op[i][1], op[i][2]);
    }
    return 0;
}