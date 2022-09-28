#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

#define maxn 3010
#define LINF 23333333333333333
#define IINF 2147483647
using ll = long long;

long double dp[maxn][maxn], p, ans = 0;

int main()
{
    int n;
    dp[0][0] = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%Lf", &p);
        for (int j = 0; j < i; j++) {
            dp[i][j + 1] += dp[i - 1][j] * p;
            dp[i][j] += dp[i - 1][j] * (1.0 - p);
        }
    }
    for (int i = n / 2 + 1; i <= n; i++)
        ans += dp[n][i];
    printf("%.15Lf\n", ans);
    return 0;
}