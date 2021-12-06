//Author: InzamZ

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define IF(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define DF(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 210;
const int maxb = 510;
const int inf = 1e9;
const ll Inf = 1e18;

bool flag = false;
int T = 1, n;
ll a[maxn], mid, l, r, h;

bool check(ll x)
{
    ll res = x;
    for (int i = 1; i < n; ++i) {
        if (a[i] + x <= a[i + 1]) res += x;
        else
            res += (a[i + 1] - a[i]);
    }
    return res < h;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        int cnt = 0;
        scanf("%d %lld", &n, &h);
        for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
        l = 0;
        r = h;
        while (l + 1 < r) {
            mid = (l + r) >> 1;
            if (check(mid))
                l = mid;
            else
                r = mid;
        }
        printf("%lld\n", r);
    }
    return 0;
}