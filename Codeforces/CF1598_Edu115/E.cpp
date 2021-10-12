//Author: InzamZ

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define IF(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define DF(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e3 + 10;
const int maxb = 510;
const int inf = 1e9;
const ll Inf = 1e18;

bool flag = false;
int T = 1, n, m, q, ans = 0, cnt = 0;
int imap[maxn][maxn], dp1[maxn][maxn], dp2[maxn][maxn];

int main()
{
    // scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &q);
        cnt = m * n;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                imap[i][j] = 1;
                dp1[i][j] = dp2[i][j - 1] + 1;//row
                dp2[i][j] = dp1[i - 1][j] + 1;//col
                ans += dp1[i][j] + dp2[i][j];
            }
        // printf("%d\n", ans - cnt);
        while (q--) {
            int i, j;
            scanf("%d %d", &i, &j);
            imap[i][j] ^= 1;
            if (imap[i][j]) {
                ++cnt;
                ans -= dp1[i][j] + dp2[i][j];
                dp1[i][j] = 1 + dp2[i][j - 1];
                dp2[i][j] = dp1[i - 1][j] + 1;
                ans += dp1[i][j] + dp2[i][j];
                // printf("%d\n", ans - cnt);
            } else {
                --cnt;
                ans -= dp1[i][j] + dp2[i][j];
                dp1[i][j] = dp2[i][j] = 0;
                // printf("%d\n", ans - cnt);
            }
            while (i <= n && j <= m) {
                if (j != m) {
                    ans -= dp1[i][j + 1];
                    dp1[i][j + 1] = imap[i][j + 1] * (1 + dp2[i][j]);
                    ans += dp1[i][j + 1];
                    // printf("%d\n", ans - cnt);
                }
                if (i != n) {
                    ans -= dp2[i + 1][j];
                    dp2[i + 1][j] = imap[i + 1][j] * (1 + dp1[i][j]);
                    ans += dp2[i + 1][j];
                    // printf("%d\n", ans - cnt);
                }
                if (i != n && j != m) {
                    ans -= dp2[i + 1][j + 1] + dp1[i + 1][j + 1];
                    dp2[i + 1][j + 1] = imap[i + 1][j + 1] * (1 + dp1[i][j + 1]);
                    dp1[i + 1][j + 1] = imap[i + 1][j + 1] * (1 + dp2[i + 1][j]);
                    ans += dp2[i + 1][j + 1] + dp1[i + 1][j + 1];
                    // printf("%d\n", ans - cnt);
                }
                ++i;
                ++j;
            }
            printf("%d\n", ans - cnt);
        }
    }
    return 0;
}