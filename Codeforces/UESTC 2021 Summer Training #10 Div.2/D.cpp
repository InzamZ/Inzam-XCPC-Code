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

int a[maxn];

int main()
{
    int T = 1, n, ans = 0;
    ll sum = 0;
    scanf("%d", &T);
    while (T--) {
        sum = ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        if (sum == 0)
            printf("NO\n");
        else {
            printf("YES\n");
            sort(a + 1, a + 1 + n);
            if (sum > 0) {
                for (int i = n; i >= 1; --i)
                    printf("%d%c", a[i], i == 1 ? '\n' : ' ');
            }
            else {
                for (int i = 1; i <= n; ++i)
                    printf("%d%c", a[i], i == n ? '\n' : ' ');
            }
        }
    }
    return 0;
}