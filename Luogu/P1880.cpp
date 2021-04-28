#include <bits/stdc++.h>
using namespace std;

const int maxn = 220;
const int IINF = 1e9;

using ll = long long;

int sum[maxn * 2], dpmax[maxn][maxn], dpmin[maxn][maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, ans;
    cin >> n;
    for (int i = 1; i <= 2 * n; ++i) {
        if (i <= n) {
            cin >> sum[i];
            sum[i + n] = sum[i];
        }
        sum[i] += sum[i - 1];
    }
    for (int len = 1; len <= n; ++len) {
        for (int i = 1; i <  2 * n; ++i) {
            int j = i + len - 1;
            if (len == 1) {
                dpmax[i][j] = dpmin[i][j] = 0;
                continue;
            }
            dpmax[i][j] = 0;
            dpmin[i][j] = IINF;
            for (int k = i; k < j && k <= 2 * n - 1; ++k) {
                dpmax[i][j] = max(dpmax[i][j], dpmax[i][k] + dpmax[k + 1][j] + sum[j] - sum[i - 1]);
                dpmin[i][j] = min(dpmin[i][j], dpmin[i][k] + dpmin[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }
    ans = dpmin[n][2 * n - 1];
    for (int i = 1; i < n; ++i)
        ans = min(ans, dpmin[i][i + n - 1]);
    cout << ans << endl;
    ans = dpmax[n][2 * n - 1];
    for (int i = 1; i < n; ++i)
        ans = max(ans, dpmax[i][i + n - 1]);
    cout << ans << endl;
    return 0;
}