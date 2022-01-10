#include <bits/stdc++.h>
using namespace std;
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;
#define pii pair<int,int>
#define pdd pair<double,double>

int T = 1, n;
ll a[100010], b[100010];
ll ans = 1e18, c;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%lld", &a[i]);
        for (int i = 0; i < n; ++i)
            scanf("%lld", &b[i]);
        sort(a, a + n);
        sort(b, b + n);
        ll y = 0, m = 0;
        int r = n - n / 4;
        for (int i = n - 1; i >= n - r; --i) {
            y += a[i];
            m += b[i];
        }
        int cnt = n - r, cnt2 = n - r - 1;
        ans = 0;
        if (y >= m)
            printf("%lld\n", ans);
        else {
            while (y < m) {
                ans++;
                if ((n + ans) % 4 != 0 && cnt2 >= 0) {
                    m += b[cnt2];
                    cnt2--;
                }
                if ((n + ans) % 4 == 0 && cnt >= 0) {
                    y += (100 - a[cnt]);
                    cnt++;
                }
                else if ((n + ans) % 4 == 0 ) ;
                else
                    y += 100;
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}