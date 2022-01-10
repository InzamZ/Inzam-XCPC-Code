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

int cnt[3];

int main()
{
    int T = 1, n, ans = 0;
    // scanf("%d", &T);
    while (T--) {
        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &ans);
            cnt[ans]++;
        }
        if (cnt[1] == 0 || cnt[2] == 0) {
            for (int i = 1; i <= cnt[1]; ++i)
                printf("1 ");
            for (int i = 1; i <= cnt[2]; ++i)
                printf("2 ");
        }
        else {
            printf("2 1 "); cnt[2]--; cnt[1]--;
            for (int i = 1; i <= cnt[2]; ++i)
                printf("2 ");
            for (int i = 1; i <= cnt[1]; ++i)
                printf("1 ");
        }
    }
    return 0;
}