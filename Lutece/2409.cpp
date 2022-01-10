#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
using ll = long long;
const ll mod = 1000000007;

char a[maxn], b[maxn];
int bi[maxn];
int dp[maxn][10][10];

ll dfs(int pos, int pre1, int pre2, bool limit, bool lead)
{
    if (pos == -1 ) {
        //cout << pre1 << pre2 << endl;
        return 1;
    }
    if (!limit && !lead && dp[pos][pre1][pre2] != -1)
        return dp[pos][pre1][pre2];
    int up = limit ? bi[pos] : 9;
    ll ans = 0;
    for (int i = 0; i <= up; ++i) {
        if ( i != pre1 && i != pre2 && !lead )
            ans += dfs(pos - 1, pre2, i, limit && i == bi[pos], 0), ans %= mod;
        else if (lead)
            ans += dfs(pos - 1, pre2, i == 0 ? 10 : i, limit && i == bi[pos], lead && i == 0), ans %= mod;
    }
    if (!limit && !lead && pre1 != 10 && pre2 != 10)
        dp[pos][pre1][pre2] = ans % mod;
    return ans;
}

ll solve(char *x)
{
    int pos = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = strlen(x) - 1; i >= 0; --i)
        bi[pos++] = x[i] - 48;
    return dfs(pos - 1, 10, 10, true, true);
}

int main()
{
    ll ans = 0, numr = 0, numl = 0, i = 0;
    scanf("%s%s", a, b);
    for (i = strlen(a) - 1; a[i] == '0'; --i) ;
    a[i] = a[i] - 1;
    while (i < strlen(a))
        a[++i] = '9';
    int pos = 0;
    for (int i = 0; i < strlen(a); ++i)
        numl = (numl * 10 + a[i] - 48) % mod;
    for (int i = 0; i < strlen(b); ++i)
        numr = (numr * 10 + b[i] - 48) % mod;
    ans = (solve(b) - solve(a)) % mod;
    printf("%lld\n", ((numr - numl) + mod - ans) % mod);
    return 0;
}