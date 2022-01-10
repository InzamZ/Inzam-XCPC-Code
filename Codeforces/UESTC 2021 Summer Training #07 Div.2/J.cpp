#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e3 + 10;
const int maxb = 110;
const int inf = 1e9;
const __int128 Inf = 1e20;


int T = 1, n;
__int128 ans = 0, prime[15] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

void dfs(__int128 primeid, __int128 now, int cnt)
{
    if (primeid > 10)
        return ;
    if (cnt == n) {
        ans = min(ans, now);
        return ;
    }
    if (now * prime[primeid] > ans)
        return ;
    if (cnt > n)
        return ;
    for (int i = 1; i <= 64; ++i) {
        now *= prime[primeid];
        if (now > ans)
            break;
        dfs(primeid + 1, now, cnt * (i + 1));
    }
}

int main()
{
    // scanf("%d", &T);
    __int128 a = 1ll;
    while (T--) {
        ans = Inf;
        scanf("%d", &n);
        dfs(a, a, a);
        printf("%lld\n", ll(ans));
    }
    return 0;
}