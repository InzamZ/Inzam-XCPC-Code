#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int mod = 1e9 + 7;
using ll = long long;

char m[maxn][maxn];
ll dp[maxn][maxn];

int main()
{
    int h, w;
    scanf("%d%d", &h, &w);
    for (int i = 0; i < h; i++)
        scanf("%s", m[i]);
    dp[0][0] = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (m[i][j] == '#')
                dp[i][j] = 0;
            else if ((i == 0 && j == 0) || (m[i - 1][j] == '#' && m[i][j - 1] == '#'))
                continue;
            else if (i == 0 || m[i - 1][j] == '#')
                dp[i][j] = dp[i][j - 1];
            else if (j == 0 || m[i][j - 1] == '#')
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= mod;
        }
    }
    printf("%lld", dp[h - 1][w - 1] % mod);
    return 0;
}