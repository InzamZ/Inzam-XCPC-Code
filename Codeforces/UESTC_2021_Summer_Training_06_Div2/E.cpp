#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxb = 210;
const int inf = 1e9;
const ll Inf = 1e18;

int maxk[maxb];

int main()
{
    int T = 1, n, k = 0;
    for (int i = 1, res = 2; i <= 200; ++i)
        if (res - 1 <= 200)
            maxk[i] = res - 1, res *= 2;
        else
            maxk[i] = res, res = 300;
    // scanf("%d",&T);
    while (T--) {
        scanf("%d %d", &n, &k);
        if (n < maxk[k])
            printf("NO\n");
        else {
            printf("YES\n");
            for (int i = 1, res = 1; i < k; ++i, res *= 2)
                printf("%d ", res);
            printf("%d\n", n - maxk[k - 1]);
        }
    }
    return 0;
}