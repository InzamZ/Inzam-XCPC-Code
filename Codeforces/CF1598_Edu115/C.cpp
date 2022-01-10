//Author: InzamZ
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define IF(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define DF(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 2e5 + 10;
const int maxb = 10;
const int inf = 1e9;
const ll Inf = 1e18;

bool flag = true;
int T = 1, n, len;
ll d[maxn], c[maxn], ans = 0;
long double sum = 0;
map<ll, ll>m;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        m.clear();
        sum = ans = 0;
        IF(i, 1, n) {
            scanf("%lld", &d[i]);
            sum += d[i];
            ++m[d[i]];
        }
        sum /= n;
        sort(d + 1, d + 1 + n);
        len = unique(d + 1, d + 1 + n) - (d + 1);
        int i = 1, j = len;
        for (i = 1; i < j; i++) {
            for (; j > i;) {
                if (d[i] + d[j] == sum * 2) {
                    ans += m[d[i]] * m[d[j]];
                    --j;
                    break;
                } else if (d[i] + d[j] > sum * 2) --j;
                else break;
            }
        }
        for (int i = 1; i <= len; ++i)
            if (d[i] == sum) {
                ans += (m[d[i]] * (m[d[i]] - 1) / 2);
            }
        printf("%lld\n", ans);
    }
    return 0;
}