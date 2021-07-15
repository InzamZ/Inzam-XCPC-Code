#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;
const int maxn = 1e4 + 5;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

char s[maxn];

int main()
{
    int T = 1, n;
    ll  a, b, cnt;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%lld%lld", &n, &a, &b);
        scanf("%s", s);
        cnt = 1;
        for (int i = 1; i < strlen(s); ++i) {
            if (s[i] == s[i - 1])
                continue;
            else
                ++cnt;
        }
        if (strlen(s) == 1 )
            cnt = 1;
        else if (cnt % 2 == 1)
            cnt = (cnt + 1) / 2;
        else if (cnt % 2 == 0)
            cnt = cnt / 2 + 1;
        ll ans = max(b * cnt + (ll)strlen(s) * a, (ll)strlen(s) * (a + b)) ;
        printf("%lld\n", ans);
    }
    return 0;
}