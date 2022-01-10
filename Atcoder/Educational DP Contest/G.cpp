#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
using ll = long long;

int f[maxn], ans = 0;
vector<int>edge[maxn];

int dfs(int node);

int dfs(int node)
{
    f[node] = 0;
    for (int i = 0; i < edge[node].size(); i++) {
        if (f[edge[node][i]] == -1)
            dfs(edge[node][i]);
        f[node] = max(f[node], 1 + f[edge[node][i]]);
    }
    return f[node];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    memset(f, -1, sizeof(int) * (n + 1));
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (f[i] == -1)
            dfs(i);
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}