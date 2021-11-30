//Author: InzamZ

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define IF(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define DF(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e5 + 10;
const int maxb = 510;
const int inf = 1e9;
const ll Inf = 1e9;

bool flag = false;
int T = 1, n;
ll a[maxn], b[maxn];

ll gcd(ll x, ll y)
{
    return y == 0 ? x : gcd(y, x % y);
}

int main()
{
    a[0] = 1;
    for (int i = 1;; ++i) {
        a[i] = (1ll * (1ll + i) * (a[i - 1])) / gcd(a[i - 1], (1ll + i));
        if (a[i] >= Inf)
            break;
    }
    scanf("%d", &T);
    while (T--) {
        flag = 1;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &b[i]);
            if (a[i] && b[i] % a[i] == 0)
                flag = 0;
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}