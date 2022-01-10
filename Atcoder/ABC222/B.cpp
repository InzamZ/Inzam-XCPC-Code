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
int T = 1, n, p, a, ans = 0;

int main()
{
    // scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &p);
        IF(i, 1, n) {
            scanf("%d", &a);
            if (a < p) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}