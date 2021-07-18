#include <bits/stdc++.h>
using namespace std;
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;
#define pii pair<int,int>
#define pdd pair<double,double>

const double pi = acos(-1.0);

ll T = 1, n, k;
map<int, int>col;
int a[300010], cnt[300010], res = 0, ans = 0;

int main()
{
    while (T--) {
        scanf("%lld %lld", &n, &k);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            col[a[i]] = i;
        }
        for (int i = 1; i <= k; ++i) {
            int colnum = col[a[i]];
            if (cnt[colnum] == 0)
                ans++;
            cnt[colnum]++;
        }
        res = ans;
        for (int i = k + 1; i <= n; ++i) {
            int colnum = col[a[i]];
            --cnt[col[a[i - k]]];
            if (cnt[col[a[i - k]]] == 0)
                res--;
            if (cnt[colnum] == 0)
                res++;
            cnt[colnum]++;
            ans = max(ans, res);
        }
        printf("%d\n", ans);
    }
    return 0;
}