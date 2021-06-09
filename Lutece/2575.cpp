#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
using ll = long long;
const ll inf = -2e17;
vector<int>e[maxn];
ll dp[maxn][maxn], val[maxn], siz[maxn];
ll n, m, f;

int dfs1(int root)
{
    int ans = 1;
    for (int i = 0; i < e[root].size(); ++i)
        ans += dfs1(e[root][i]);
    siz[root] = ans;
    return ans;
}

void dfs2(int root)
{
    for (int i = 1; i <= m; ++i)
        dp[root][i] = val[root];
    for (int i = 0; i < e[root].size(); ++i) {
        dfs2(e[root][i]);
        for (int j = min(m, siz[root]); j > 0; --j)
            for (int k = 0; k <= j - 1; ++k)
                dp[root][j] = max(dp[root][j], dp[root][j - k] + dp[e[root][i]][k]);
    }
}
int main()
{
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n - 1; ++i) {
        scanf("%lld", &f);
        e[f].push_back(i + 1);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &val[i]);
    siz[1] = dfs1(1);
    dfs2(1);
    printf("%lld\n", dp[1][m]);
    return 0;
}