//Author: InzamZ

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define IF(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define DF(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 2e5 + 10;
const int maxb = 510;
const int inf = 1e9;
const ll Inf = 1e18;

bool flag = false;
int T = 1, n;
ll m, ans = 0;

ll cnt[maxn][20];

int main()
{
    for (int i = 1; i < maxn; ++i) {
        int tmp = i;
        for (int j = 0; j <= 20; ++j)
            cnt[i][j] = cnt[i - 1][j];
        for (int j = 0; j <= 20; ++j) {
            if (tmp == 0) {
                ++cnt[i][j];
            } else {
                if (tmp & 1) ;
                else ++cnt[i][j];
                tmp >>= 1;
            }
        }
    }
    scanf("%d", &T);
    while (T--) {
        int l, r;
        ans = 1e9;
        scanf("%d %d", &l, &r);
        for (int j = 0; j <= 20; ++j) {
            ans = min(ans, cnt[r][j] - cnt[l - 1][j]);
            // printf("%lld %lld\n", cnt[r][j], cnt[l - 1][j]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}