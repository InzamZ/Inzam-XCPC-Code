#include <bits/stdc++.h>
using namespace std;
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;
#define pii pair<int,int>
#define pdd pair<double,double>

const double pi = acos(-1.0);
const int maxn = 1005;
const int inf = 1e9;
const ll Inf = 1e18;
// struct point {
//     double x, y;
// } p[maxn];
ll T = 1, n, m, sum = 0, ans;
bool flag = true;

map<ll, int>pow2;
int cnt[maxn], beg[maxn];

int main()
{
    ll res = 1;
    for (int i = 0 ; i <= 60; ++i, res *= 2)
        pow2[res] = i;
    scanf("%lld", &T);
    while (T--) {
        memset(cnt, 0, sizeof(cnt));
        memset(beg, 0, sizeof(beg));
        flag = true;
        ans = sum = 0;
        scanf("%lld %lld", &n, &m);
        for (int i = 1; i <= m; ++i) {
            ll a;
            scanf("%lld", &a);
            ++cnt[(pow2[a])];
            sum += a;
        }
        ll nclone = n;
        if (sum < n)
            printf ("-1\n");
        else {
            for (int i = 0; nclone; ++i, nclone /= 2) {
                if (n & (1ll << i)) {
                    if (!cnt[i]) {
                        int j = 1;
                        while (!cnt[i + j])
                            ++j;
                        --cnt[i + j];
                        --j;
                        for (; j >= 0; --j, ++ans)
                            ++cnt[i + j];
                    }
                    --cnt[i];
                }
                cnt[i + 1] += cnt[i] / 2;
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}