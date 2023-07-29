//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, d, x, ans = 0, a[maxn], fa[maxn], D = 0, DFlag[maxn], DLeaf = 0, rt, anss = 1;
bool vis[maxn], Ran[maxn];
vector<int>e[maxn], v;
string s;

void dfs(int u, int f, int dep) {
    vis[u] = 1;
    fa[u] = f;
    if (dep > D)
        DLeaf = u, D = dep;
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        if (v == f)
            continue;
        dfs(v, u, dep + 1);
    }
}

void dfs2(int u, int dep) {
    vis[u] = 1;
    if (dep == d) {
        ++ans;
        // cout << "Found: " << u << '\n';
        for (int i = 0; i < e[u].size(); i++) {
            int v = e[u][i];
            if (vis[v])
                continue;
            dfs2(v, 1);
        }
        return ;
    }
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        if (vis[v])
            continue;
        dfs2(v, dep + 1);
    }
    return ;
}

int solve() {
    ans = 1;
    cin >> n >> d;
    for (int i = 1; i < n; i++) {
        cin >> x;
        e[i].push_back(x);
        e[x].push_back(i);
    }
    for (int i = 0; i < n; i++)
        vis[i] = 0;
    rt = 0;
    dfs(rt, -1, 1);
    rt = DLeaf;
    while (1) {
        DFlag[DLeaf] = 1;
        if (DLeaf == 0)
            break;
        DLeaf = fa[DLeaf];
    }
    for (int i = 0; i < n; i++)
        vis[i] = 0;
    dfs(rt, -1, 1);
    while (1) {
        DFlag[DLeaf] = 1;
        if (DLeaf == 0)
            break;
        DLeaf = fa[DLeaf];
    }
    // for (int i = 0; i < n; i++)
    //     cout << DFlag[i] << ' ';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < e[i].size() - 1; j++)
            if (DFlag[e[i][j]]) {
                swap(e[i][j], e[i][e[i].size() - 1]);
                break;
            }
    }

    for (int i = 0; i < n; i++)
        vis[i] = 0;
    ans = 1;
    dfs2(rt, 0);
    anss = max(anss, ans);

    for (int i = 0; i < n; i++)
        vis[i] = 0;
    ans = 1;
    dfs2(DLeaf, 0);
    anss = max(anss, ans);

    for (int i = 0; i < n; i++) {
        swap(e[i][0], e[i][e[i].size() - 1]);
    }

    for (int i = 0; i < n; i++)
    vis[i] = 0;
    ans = 1;
    dfs2(rt, 0);
    anss = max(anss, ans);

    for (int i = 0; i < n; i++)
        vis[i] = 0;
    ans = 1;
    dfs2(DLeaf, 0);
    anss = max(anss, ans);

    cout << anss << '\n';
    return 0;
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    srand(time(0));
    // cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}