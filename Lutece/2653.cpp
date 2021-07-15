#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;
const int maxn = 1e5 + 5;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

int gcd (int x, int y)
{
    if (x < y)
        swap(x, y);
    return x == y ? x : gcd(y, x % y);
}

int a[maxn], b[maxn];
int main()
{
    int T = 1, n, m, ans;
    // scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) {
            if (i == 1)
                ans = a[1];
            else
                ans = gcd(ans, a[i]);
        }
        for (int i = 1; i <= m; ++i) {
            scanf("%d", &b[i]);
            printf("%d%c", gcd(b[i], ans), i == n ? '\n' : ' ');
        }
    }
    return 0;
}