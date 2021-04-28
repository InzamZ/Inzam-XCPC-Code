#include <cstdio>
#include <iostream>
using namespace std;

#define maxn 100010
#define INF 23333333333333
long long h[maxn], dp[maxn];


int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &h[i]);
        if (i != 1)
            dp[i] = INF;
        for (int j = 1; j <= k && i - j > 0; j++)
            dp[i] = min(dp[i - j] + abs(h[i] - h[i - j]), dp[i]);
    }
    printf("%lld\n", dp[n]);
    return 0;
}