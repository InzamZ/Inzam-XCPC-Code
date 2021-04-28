#include <bits/stdc++.h>
using namespace std;
const int maxn = 3010;
using ll = long long;

char s1[maxn], s2[maxn], ans[maxn];
int len1, len2;
int dp[maxn][maxn];

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, cur = 0;
    scanf("%s%s", s1 + 1, s2 + 1);
    len1 = strlen(s1 + 1);
    len2 = strlen(s2 + 1);
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (s1[i] == s2[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cur = dp[len1][len2];
    while (len1 && len2) {
        if (s1[len1] == s2[len2]) {
            ans[cur--] = s1[len1];
            --len1;
            --len2;
        }
        else if (dp[len1 - 1][len2] > dp[len1][len2 - 1])
            --len1;
        else
            --len2;
    }
    printf("%s\n", ans + 1);
    return 0;
}