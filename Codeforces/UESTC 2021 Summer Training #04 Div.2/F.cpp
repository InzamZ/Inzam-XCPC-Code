#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    int T = 1, n;
    ll c, s;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld", &c, &s);
        if (c > s)
            swap(c, s);
        ll res = c - (s - c);
        if (res >= 0 && res % 3 == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}