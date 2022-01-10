#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 2e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

ll c[maxn];

ll dp[maxn][2][2];
vector<ll>son[maxn];
int T = 1, n, a, b, d;
ll ans = 0;

int main()
{
    // scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%d", &n);
        for (int i = 2; i <= n; ++i) {
            scanf("%d", &a);
            son[a].push_back(i);
        }
        for (int i = 1; i <= n; ++i)
            scanf("%lld", &c[i]);
        for (int i = n; i >= 1; --i) {
            dp[i][0][0] = 0; dp[i][1][0] = c[i]; dp[i][1][1] = -Inf;
            for (int j = 0; j < son[i].size(); ++j) {
                int res = son[i][j];
                a = dp[i][0][0] + max (dp[res][0][0], dp[res][1][1]);
                b = max(dp[i][1][1] + dp[res][1][0], dp[i][1][0] + dp[res][0][0]);
                d = max(dp[i][1][0] + dp[res][1][0], dp[i][1][1] + dp[res][0][0]);
                dp[i][0][0] = a; dp[i][1][0] = b; dp[i][1][1] = d;
            }
        }
        printf("%lld\n", max(dp[1][0][0], dp[1][1][1]));
    }
    return 0;
}
/*
5
1 1 3 4
1 5 1 5 5
*/