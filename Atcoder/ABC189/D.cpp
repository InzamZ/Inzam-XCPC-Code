#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;
const int maxn = 100;
char s[10];
ll a[maxn] = {0}, dp[maxn][0];

int main()
{
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        memset(s, 0, sizeof(s));
        scanf("%s", s);
        a[i] = (strcmp(s, "AND") == 0) ? 1 : 0;
    }
    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            dp[i][0] = dp[i - 1][0] * 2 + dp[i - 1][1];
            dp[i][1] = dp[i - 1][1];
        }
        else {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][0] + dp[i - 1][1] * 2;
        }
    }
    printf("%lld\n", dp[n][1]);
    return 0;
}