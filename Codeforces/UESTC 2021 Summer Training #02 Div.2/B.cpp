#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;

const int maxn = 1e5 + 5;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

bool vis[maxn];
ll a[maxn], cnt[maxn];

int main()
{
    int T = 1, n;
    bool flag = false;
    // scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        cnt[0] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
            cnt[i] = cnt[i - 1];
            if (!vis[a[i]]) {
                ++cnt[i];
                vis[a[i]] = 1;
            }
        }
        memset(vis, 0, sizeof(vis));
        for (int i = n; i > 1; --i) {
            if (!vis[a[i]]) {
                cnt[0] += cnt[i - 1];
                vis[a[i]] = 1;
            }
        }
        printf("%lld\n", cnt[0]);
    }
    return 0;
}