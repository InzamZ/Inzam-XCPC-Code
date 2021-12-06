//Author: InzamZ

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define IF(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define DF(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 5e5 + 10;
const int maxb = 510;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 998244353;

int T = 1, n;
ll a[maxn], cnt1 = 0;
ll ans1[maxn], ans2[maxn], ans = 0;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        cnt1 = ans = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &a[i]);
            if (a[i] == 1) {
                cnt1 = cnt1 * 2 + 1;
                cnt1 %= mod;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (a[i] == 0) {
                ans += (1 + ans1[a[i]] % mod);
                ans %= mod;
                ans1[a[i]] = (1 + ans1[a[i]] * 2 % mod) % mod;
                ans1[a[i]] %= mod;
                if (ans2[a[i] + 2]) {
                    ans += (ans2[a[i] + 2]);
                    ans2[a[i] + 2] = (ans2[a[i] + 2] * 2) % mod;
                    ans2[a[i] + 2] %= mod;
                }
            } else {
                ans += ((ans1[a[i] - 1] + ans1[a[i]]) % mod);
                ans %= mod;
                if (a[i] >= 2) {
                    ans += (ans1[a[i] - 2] + ans2[a[i]]);
                    ans %= mod;
                    ans2[a[i]] = (ans1[a[i] - 2] + ans2[a[i]] * 2) % mod;
                    ans2[a[i]] %= mod;
                }
                if (ans2[a[i] + 2]) {
                    ans += (ans2[a[i] + 2]);
                    ans2[a[i] + 2] = (ans2[a[i] + 2] * 2) % mod;
                    ans2[a[i] + 2] %= mod;
                }
                ans %= mod;
                ans1[a[i]] = (ans1[a[i] - 1] + ans1[a[i]] * 2 % mod) % mod;
                ans1[a[i]] %= mod;
            }
        }
        ans += cnt1;
        printf("%lld\n", ans % mod);
        for (int i = 0; i <= n; ++i) {
            ans2[i] = ans1[i] = 0;
        }
    }
    return 0;
}