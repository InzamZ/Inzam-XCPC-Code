//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("/out.txt" , "w", stdout);
const int maxn = 2e3 + 10;
#define mod (998244353ll)
ll ans = 0;
int n, m, k, s, t, x;
vector<int>e[maxn];
int dp[maxn][maxn][2];
int main()
{
    FIO;
    cin >> n >> m >> k >> s >> t >> x;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dp[0][s][0] = 1;
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int l = 0; l < e[j].size(); ++l) {
                int v = e[j][l];
                if (j != x) {
                    dp[i][j][0] = (dp[i - 1][v][0] + dp[i][j][0]) % mod;
                    dp[i][j][1] = (dp[i - 1][v][1] + dp[i][j][1]) % mod;
                }
                else {
                    dp[i][j][0] = (dp[i - 1][v][1] + dp[i][j][0]) % mod;
                    dp[i][j][1] = (dp[i - 1][v][0] + dp[i][j][1]) % mod;
                }
            }
        }
    }
    cout << dp[k][t][0] << '\n';
    return 0;
}