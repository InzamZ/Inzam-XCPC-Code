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
    int T = 1, n, ans = 0, sum, mx;
    scanf("%d", &T);
    while (T--) {
        sum = mx = ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            int a;
            scanf("%d", &a);
            ans ^= a;
            sum += a;
        }
        if (sum - mx - mx == 1)
            printf("%HL\n");
        else
            printf("%s\n", ans % 2 == 0 ? "HL" : "T");
    }
    return 0;
}