#include <bits/stdc++.h>
using namespace std;

const int maxn = 310;

int cnt[4] = {0};
double dp[maxn][maxn][maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        ++cnt[x];
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; i + j <= n; j++)
            for (int k = 0; i + j + k <= n; k++) {
                if (i == 0 && j == 0 && k == 0)
                    continue;
                double sum = i + j + k;
                double &r = dp[k][j][i];
                r = n;
                if (k)
                    r += dp[k - 1][j][i] * k;
                if (j)
                    r += dp[k + 1][j - 1][i] * j;
                if (i)
                    r += dp[k][j + 1][i - 1] * i;
                r /= sum;
            }
    cout << fixed << setprecision(12) << dp[cnt[1]][cnt[2]][cnt[3]] << endl;
    return 0;
}