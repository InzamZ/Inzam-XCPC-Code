#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e6 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

int ans[maxn];

int main()
{
    int T = 1, n, cnt = 0, k;
    scanf("%d", &T);
    while (T--) {
        cnt = 0;
        scanf("%d %d", &n, &k);
        for (int i = 1; i < 2 * k - n; ++i)
            ans[++cnt] = i;
        for (int i = k; i >= 2 * k - n; --i)
            ans[++cnt] = i;
        for (int i = 1; i <= k; ++i)
            printf("%d%c", ans[i], i == k ? '\n' : ' ');
    }
    return 0;
}