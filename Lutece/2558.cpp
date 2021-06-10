#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5e5 + 10;
vector<int>e[maxn];
int ans[maxn];
int dfs(int rt)
{
    if (ans[rt])
        return ans[rt];
    int cnt = 1;
    for (int i = 0; i < e[rt].size(); ++i)
        cnt += dfs(e[rt][i]);
    return ans[rt] = cnt;
}
int main()
{
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d", &a, &b);
        e[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i) {
        sort(e[i].begin(), e[i].end());
        unique(e[i].begin(), e[i].end());
    }
    for (int i = 1; i <= n; ++i)
        if (!ans[i])
            ans[i] = dfs(i);
    for (int i = 1; i <= n; ++i)
        printf("%d\n", ans[i]);
    return 0;
}