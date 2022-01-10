#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

using ll = long long;
const int maxn = 20;
const ll inf = 2e18;
#define reg register
#define FOR(a,b,c) for(reg int a=b;a<=c;++a)

ll dp[maxn][1 << maxn], w[maxn], ans = inf;
int n, T;
char s[maxn];
vector<int>g[maxn], a[maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ans = inf;
        FOR(i, 0, n) FOR(j, 0, (1 << n)) dp[i][j] = inf;
        FOR(i, 0, n) {
            g[i].clear();
            a[i].clear();
        }
        FOR(i, 0, n - 1) {
            scanf("%s", s);
            FOR(j, 0, n - 1) {
                if (s[j] == '1')
                    g[i].push_back(j);
            }
        }
        FOR(i, 0, n - 1) {
            scanf("%s", s);
            FOR(j, 0, n - 1) {
                if (s[j] == '1')
                    a[i].push_back(j);
            }
        }
        FOR(i, 0, n - 1) scanf("%lld", &w[i]);
        dp[0][0] = 0;
        FOR(i, 0, n - 1) {
            FOR(j, 0, (1 << n) - 1) {
                ll ls = j & ((1 << i) - 1), rs = j & ((1 << n) - (1 << i));
                bool ok = 1;
                for (int k = 0; k < a[i].size() && ok; ++k) {
                    if (ls & (1 << a[i][k]))
                        ok = 0;
                }
                if ((rs >> i & 1))
                    dp[i + 1][ls | (rs ^ (1 << i))] = min(dp[i + 1][ls | (rs ^ (1 << i))], dp[i][j]);
                if (dp[i][j] == inf)
                    continue;
                for (int t = 0; t < (1 << g[i].size()); ++t) {
                    if (!ok && t > 0)
                        break;
                    ll cost = 1, ts = rs;
                    bool cnt = 0;
                    for (int k = 0; k < g[i].size(); ++k) {
                        if (t & (1 << k)) {
                            cost *= w[i]; ts |= (1 << g[i][k]);
                            cnt = true;
                        }
                    }
                    if (!(ts >> i & 1))
                        continue;
                    if (t == 0)
                        dp[i + 1][ls | (rs ^ (1 << i))] = min(dp[i + 1][ls | (rs ^ (1 << i))], dp[i][j]);
                    else
                        dp[i + 1][ls | ts] = min(dp[i + 1][ls | ts], dp[i][j] + cost * cnt);
                    if ((ts >> i) + 1 == (1 << (n - i)))
                        ans = min(ans, dp[i + 1][ls | ts]);
                }
            }
        }
        for (int t = 1; t <= (1 << n ) ; ++t)
            ans = min(ans, dp[n][t]);
        if (ans == inf)
            ans = -1;
        printf("%lld\n", ans);
    }
    return 0;
}