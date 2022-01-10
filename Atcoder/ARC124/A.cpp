#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 5e5 + 10;
const int maxb = 2e5 + 10;
const int mod = 998244353;
const ll Inf = 1e18;

ll gcd(ll x, ll y)
{
    return y == 0 ? x : gcd(y, x % y);
}

int T = 1, n, K;
int a[maxb];
bool flag = false;

void dfs(int aim, int rt, int beg, int res)
{
    if (res == a[aim] || res == -a[aim] || res == 0) {
        flag = true;
        return ;
    }
    for (int i = beg; !flag && i <= n; ++i)
        if (i != rt && i != aim)
            dfs(aim, rt, 1, res - a[i]);
}

int main()
{
    ll ans = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        flag = false;
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        for (int j = 1; !flag && j <= n; ++j)
            for (int i = 1; !flag && i <= n; ++i)
                if (i != j)
                    dfs(j, i, 1, a[i]);
        if (a[1] == 0 && n == 1)
            flag = true;
        if (a[1] != 0 && n == 1)
            flag = false;
        printf("%s", flag ? "YES\n" : "NO\n" );
    }
    return 0;
}