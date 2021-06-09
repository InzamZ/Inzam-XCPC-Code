#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
using ll = long long;
const ll mod = 998244353;

char a[maxn], b[maxn];
int bi[maxn];
ll dp[maxn][15][15];

ll dfs(int pos, int pre1, int pre2, bool limit)
{
    if (pos == -1 ) {
        //cout << pre1 << pre2 << endl;
        return 1;
    }
    if (!limit  && dp[pos][pre1][pre2] != -1 && pre2 != 10 && pre1 != 10)
        return dp[pos][pre1][pre2];
    int up = limit ? bi[pos] : 9;
    ll ans = 0;
    for (int i = 0; i <= up; ++i) {
        if (( i == 2 && pre2 == 4 )
                || ( i == 5 && pre2 == 3 && pre1 == 1 ))
            continue;
        ans += dfs(pos - 1, pre2, i, limit && i == bi[pos]), ans %= mod;
    }
    if (!limit && pre2 != 10 && pre1 != 10)
        dp[pos][pre1][pre2] = ans % mod;
    return ans % mod;
}

ll solve(char *x)
{
    int pos = 0;
    for (int i = strlen(x) - 1; i >= 0; --i)
        bi[pos++] = x[i] - 48;
    return dfs(pos - 1, 10, 10, true);
}

int main()
{
    ll ans = 0, numr = 0, numl = 0, i = 0, n;
    scanf("%lld", &n);
    for (int t = 1; t <= n; t++) {
        ans = 0, numr = 0, numl = 0, i = 0;
        bool flag = true;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        scanf("%s%s", a, b);
        if (strlen(a) > strlen(b))
            flag = false;
        else if (strlen(a) == strlen(b) && strcmp(a, b) > 0)
            flag = false;
        if (!flag)
            swap(a, b);
        for (i = strlen(a) - 1; a[i] == '0' && i >= 0 ; --i) ;
        if (i >= 0)
            a[i] = a[i] - 1;
        else
            i = 0;
        ++i;
        for (; i < strlen(a); ++i)
            a[i] = '9';
        int pos = 0;
        for (int i = 0; i < strlen(a); ++i)
            numl = (numl * 10 + a[i] - 48) % mod;
        for (int i = 0; i < strlen(b); ++i)
            numr = (numr * 10 + b[i] - 48) % mod;
        memset(dp, -1, sizeof(dp));
        ans = (solve(b) - solve(a) + mod ) % mod;
        printf("%lld\n", (((numr - numl) + mod ) % mod - ans + mod) % mod);
    }
    return 0;
}