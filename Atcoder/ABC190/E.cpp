#include <bits/stdc++.h>
using namespace std;
#define maxn (1e5 + 10)
const int inf = 0x3fffffff;

int main()
{
    ios::sync_with_stdio(false);
    int n, m, k, a, b, ans = inf;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin >> k;
    vector<int> c(n);
    for (auto &x : c) {
        cin >> x;
        x--;
    }
    auto BFS = [&](int x) {
        queue<int> q;
        vector cost(n, inf);
        cost[x] = 0;
        q.push(x);
        while (q.size()) {
            int node = q.front();
            q.pop();
            for (auto it : g[node]) {
                if (cost[it] > cost[node] + 1) {
                    cost[it] = cost[node] + 1;
                    q.push(it);
                }
            }
        }
        for (int i = 0; i < k; i++)
            cost[i] = cost[c[i]];
        cost.resize(k);
        return cost;
    };
    vector<vector<int>> cost(k);
    for (int i = 0; i < k; i++)
        cost[i] = BFS(c[i]);
    vector dp(1 << k, vector(k, inf));
    for (int i = 0; i < k; i++)
        dp[1 << i][i] = 1;
    for (int bit = 1; bit < (1 << k); bit++)
        for (int i = 0; i < k; i++) {
            if (bit & (1 << i)) {
                const int bit2 = bit ^ (1 << i);
                for (int j = 0; j < k; j++) {
                    if (bit2 & (1 << j))
                        dp[bit][i] = min(dp[bit][i], dp[bit2][j] + cost[i][j]);
                }
            }
        }
    for (auto i = dp.back().begin(); i != dp.back().end(); i++)
        ans = min(ans, *i);
    if (ans == inf)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
    return 0;
}