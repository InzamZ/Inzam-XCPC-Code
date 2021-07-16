#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;

const int maxn = 1e6 + 5;

ll s[maxn];

int main()
{
    int T = 1, a, b, c, d;
    // scanf("%d",&T);
    while (T--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for (int i = a; i <= b; ++i) {
            ++s[i + b];
            --s[i + c + 1];
        }
        for (int i = a + b; i <= maxn - 1; ++i)
            s[i] += s[i - 1];
        for (int i = a + b; i <= maxn - 1; ++i)
            s[i] += s[i - 1];
        for (int i = c; i <= d; ++i)
            s[0] += (s[maxn - 1] - s[i]);
        printf("%lld\n", s[0]);
    }
    return 0;
}

