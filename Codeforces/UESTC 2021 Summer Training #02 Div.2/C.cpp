#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;

const int maxn = 1e6 + 5;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

ll ans[maxn], cnt[maxn];


int main()
{
    int T = 1, n;
    bool flag = false;
    // scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ans[2] = 0;
        for (int i = 3; i <= n; ++i) {
            ans[i] = ans[i - 1];
            for (int j = 2; j * j <= i; ++j) {
                if (i % j)
                    continue;
                if (j * j == i)
                    ans[i] += (j * 4);
                else
                    ans[i] += ((i / j + j) * 4);
            }
        }
        printf("%lld\n", ans[n]);
    }
    return 0;
}