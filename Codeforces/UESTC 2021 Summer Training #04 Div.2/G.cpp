#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;

const int maxn = 1e4 + 5;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

ll gcd(ll x, ll y)
{
    return y == 0 ? x : gcd(y, x % y);
}

int main()
{
    int T = 1;
    ll c, s, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld %lld", &c, &s, &k);
        if (c > s)
            swap(c, s);
        ll gcdd = gcd(c, s);
        c /= gcdd; s /= gcdd;
        ll res = s % c;
        if (c == s || c + 1 == s || c * k - c + 1 >= s)
            printf("OBEY\n");
        else
            printf("REBEL\n");
    }
    return 0;
}