#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010
#define LINF 23333333333333333
#define IINF 2147483647
using ll = long long;
ll dp[MAXN], w[MAXN], v[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, W;
    cin >> N >> W;
    for (int i = 1; i <= N; i++)
        cin >> w[i] >> v[i];
    for (int i = 1; i <= N; i++) {
        for (int j = W; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    }
    cout << dp[W] << endl;
    return 0;
}