//Author: InzamZ
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define IF(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define DF(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e5 + 10;
const int maxb = 510;
const int inf = 1e9;
const ll Inf = 1e18;

bool flag = false;
int T = 1, n, m, ans = 0;
int cnt[maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &m);
            cnt[abs(m)]++;
        }
        if (cnt[0]) ans = 1;
        else ans = 0;
        for (int i = 1; i <= 100; ++i) {
            if (cnt[i] == 1) ans += 1;
            else if (cnt[i]) ans += 2;
            cnt[i] = 0;
        }
        cnt[0] = 0;
        printf("%d\n", ans);
    }
    return 0;
}