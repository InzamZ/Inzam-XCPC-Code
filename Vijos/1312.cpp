#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
using ll = long long;
int s[maxn * 3], dp[maxn * 2][maxn * 2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> s[i];
    for (int i = n + 1; i <= n * 3; ++i)
        s[i] = s[i - n];
    for (int len = 1; len <= n; ++len) {
        for (int i = 1; i <= n * 2; ++i) {
            int j = i + len - 1;
            for (int k = i; k < j && k < n * 2; ++k)
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + s[i] * s[k + 1] * s[j + 1]);
        }
    }
    for (int i = 1; i <= n; ++i)
        ans = max(dp[i][i + n - 1], ans);
    cout << ans << endl;
    return 0;
}