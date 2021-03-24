#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010
#define LINF 1e18
#define IINF 2147483647
using ll = long long;
ll dp[MAXN], w, v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, W, ans=0;
    cin >> N >> W;
    for (int i = 0; i < MAXN; i++)
        dp[i] = LINF;
    dp[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> w >> v;
        for (int j = i * 1000; j >= v; j--)
        {
            dp[j] = min(dp[j], dp[j - v] + w);
        }
    }
    for (int i = 0; i < MAXN; i++)
        if (dp[i] <= LINF)
            ans = i;
    cout << ans << endl;
    return 0;
}