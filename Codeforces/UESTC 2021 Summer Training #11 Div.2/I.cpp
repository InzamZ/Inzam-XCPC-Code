#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

int main()
{
    int T = 1, n, ans = 0;
    // scanf("%d",&T);
    while (T--) {
        ans = 0;
        scanf("%d", &n);
        if (n % 2 == 0)
            printf("NO\n");
        else {
            printf("YES\n");
            for (int i = 1; i <= n; ++i) {
                if (i % 2 == 1)
                    printf("%d ", 2 * i - 1);
                else
                    printf("%d ", 2 * i);
            }
            for (int i = 1; i <= n; ++i) {
                if (i % 2 == 1)
                    printf("%d%c", 2 * i, i == n ? '\n' : ' ');
                else
                    printf("%d%c", 2 * i - 1, i == n ? '\n' : ' ');
            }
        }
    }
    return 0;
}