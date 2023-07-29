#include<bits/stdc++.h>
#define maxn 100005
#define int long long
using namespace std;
int n, m, bj = 1;
long long s[maxn], sum;
struct hhh {
    long long k, d;
    int id;
} w[maxn];
struct hh {
    long long s;
    int id;
} ww[maxn];
bool cmp(const hhh &x, const hhh &y) {
    if (x.d != y.d)
        return x.d < y.d;
    if (x.k != y.k)
        return x.k > y.k;
    return x.id < y.id;
}
bool cmpp(const hh &x, const hh &y) {
    return x.s < y.s || (x.s == y.s && x.id < y.id);
}
bool check(int mid, long long k, long long d) {
    if (w[mid].d > d)
        return true;
    if (w[mid].d < d)
        return false;
    if (w[mid].k <= k)
        return true;
    return false;
}
int cal(long long k, long long d) {
    int l = 1, r = n, mid, ans = 0;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid, k, d))
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    return (w[ans].k <= k && w[ans].d == d) ? ans : -1;
}
signed main() {
    int i, ans; long long x, k, d;
    scanf("%lld %lld", &n, &m);
    for (i = 1; i <= n; i++)
        scanf("%lld", &x), s[i] = s[i - 1] + x;
    sum = s[n];
    if (sum == 0) {
        for (i = 1; i <= n; i++)
            ww[i].s = s[i], ww[i].id = i;
        sort(ww + 1, ww + n + 1, cmpp);
        while (m--) {
            scanf("%lld", &x);
            if (x == 0) {
                puts("0");
                continue;
            }
            int l = 1, r = n, mid; ans = 0;
            while (l <= r) {
                mid = (l + r) >> 1;
                if (ww[mid].s >= x)
                    ans = mid, r = mid - 1;
                else
                    l = mid + 1;
            }
            if (ww[ans].s != x)
                puts("-1");
            else
                printf("%lld\n", ww[ans].id);
        }
        return 0;
    }
    if (sum < 0)
        bj = -1, sum *= -1;
    for (i = 1; i <= n; i++) {
        s[i] *= bj;
        w[i].id = i;
        w[i].k = s[i] / sum;
        w[i].d = s[i] % sum;
        if (w[i].d < 0)
            w[i].d += sum, w[i].k--;
    }
    sort(w + 1, w + n + 1, cmp);
    while (m--) {
        scanf("%lld", &x);
        if (x == 0) {
            puts("0");
            continue;
        }
        x *= bj;
        k = x / sum; d = x % sum;
        if (d < 0)
            d += sum, k--;
        ans = cal(k, d);
        if (ans == -1)
            puts("-1");
        else
            printf("%lld\n", (k - w[ans].k) * n + w[ans].id);
    }
    return 0;
}