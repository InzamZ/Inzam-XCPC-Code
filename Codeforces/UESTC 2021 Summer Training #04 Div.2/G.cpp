#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll x, ll y)
{
    return y == 0 ? x : gcd(y, x % y);
}

int main()
{
    int T = 1;
    ll r, b, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld %lld", &r, &b, &k);
        if (r > b)
            swap(r, b);
        ll gcdd = gcd(r, b);
        r /= gcdd; b /= gcdd;
        ll res = b % r;
        if (r == b || r + 1 == b || r * k - r + 1 >= b)
            printf("OBEY\n");
        else
            printf("REBEL\n");
    }
    return 0;
}