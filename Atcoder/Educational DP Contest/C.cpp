#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010
#define LINF 23333333333333333
#define IINF 2147483647
using ll = long long;

ll dp[MAXN][4];
ll a, b, c, n;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        if (i == 1) {
            dp[i][1] = a;
            dp[i][2] = b;
            dp[i][3] = c;
        }
        else {
            dp[i][1] = max(dp[i - 1][2] + a, dp[i - 1][3] + a);
            dp[i][2] = max(dp[i - 1][1] + b, dp[i - 1][3] + b);
            dp[i][3] = max(dp[i - 1][1] + c, dp[i - 1][2] + c);
        }
    }
    cout << max(dp[n][1], max(dp[n][2], dp[n][3])) << endl;
    return 0;
}