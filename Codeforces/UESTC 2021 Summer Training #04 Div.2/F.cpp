#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;

const int maxn = 1e4 + 5;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

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