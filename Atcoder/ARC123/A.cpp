#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

map<ll, int>q;

int solve(ll n)
{
    if (n == 0)
        return 0;
    if (q.count(n))
        return q[n];
    ll res = n % 10, ans = 0;
    n /= 10;
    if (1 <= res && res <= 3 && solve(n) <= 1 )
        ans = 1;
    else if (2 <= res && res <= 6 && solve(n) <= 2 )
        ans = 2;
    else if (3 <= res && res <= 9 && solve(n) <= 3 )
        ans = 3;
    else if (4 <= res && res <= 9 && solve(n) <= 4 )
        ans = 4;
    else if (0 <= res && res <= 2 && solve(n - 1) <= 4 )
        ans = 4;
    else
        ans = 5;
    q[n * 10 + res] = ans;
    return ans;
}

int main()
{
    int T = 1;
    ll n;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &n);
        printf("%d\n", solve(n));
    }
    return 0;
}