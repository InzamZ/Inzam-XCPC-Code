#include <bits/stdc++.h>
using namespace std;

#define F(i,b,n)  for(int i=(b);i<(n);i++)
#define f(i,b,n)  for(int i=(b);i<=(n);i++)
#define ll long long

const int maxn = 2e5 + 10;

unordered_map < bitset < 10010 >, int > m;
bitset < 10010 > s;
int a[maxn], cnt[maxn], pri[maxn];
bool vis[maxn];

void pre()
{
    vis[1] = 1;
    for (int i = 2; i <= 1e5; ++i) {
        if (vis[i] == 0)
            pri[++(*pri)] = i;
        for (int j = 1; j <= (*pri) && i * pri[j] <= 1e5; ++j) {
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
        }
    }
}

int main()
{
    int T = 1, n, k, mx;
    ll ans = 0;
    // scanf("%d", &T);
    while (T--) {
        ans = 0, mx = 0;
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= 100000; ++i)
            cnt[i] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            ++cnt[a[i]];
            mx = max(mx, a[i]);
        }
        if (k >= 3) {
            ll temp = 1;//i^k
            for (int i = 1; i <= n; ++i) {
                temp = 1;//i^k
                for (int j = 1; j <= k && temp <= 1ll * mx * mx; ++j)
                    temp *= i;
                if (temp > 1ll * mx * mx)
                    break;
                for (int j = 1; j <= n; ++j) {
                    --cnt[a[j]];
                    if (temp % a[j] == 0 && temp / a[j] <= 1e5 && cnt[temp / a[j]]) {
                        ans += cnt[temp / a[j]];
                        // printf("%lld %d ans+= %d\n", temp, a[j], cnt[temp / a[j]]);
                    }
                    ++cnt[a[j]];
                }
            }
            ans /= 2;
        }
        else {
            pre();
            ll temp = 1, cnt = 0; //i^2
            for (int i = 1; i <= n; ++i) {
                temp = a[i];
                s.reset();
                for (int j = 1; j <= (*pri); ++j) {
                    cnt = 0;
                    while (temp % pri[j] == 0) {
                        cnt++;
                        temp /= pri[j];
                    }
                    if (cnt & 1)
                        s.set(j);
                    if (temp == 1)
                        break;
                }
                ans += m[s];
                ++m[s];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
