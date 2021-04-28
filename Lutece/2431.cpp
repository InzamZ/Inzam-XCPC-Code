#include <bits/stdc++.h>
using namespace std;
const int maxn = 5050;
using ll = long long;

char s1[maxn], s2[maxn];
int dp[maxn][maxn];

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0)
    int n;
    scanf("%d", &n);
    scanf("%s", s1 + 1);
    for (int i = 1; i <= n; i++)
        s2[n - i + 1] = s1[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i] == s2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    printf("%d",n-dp[n][n]);
    return 0;
}