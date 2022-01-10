#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;

const int maxn = 5e5 + 5;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

ll cnt[maxn];

int main()
{
    int T = 1, n, a, b;
    for (int i = 2; cnt[i - 1] <= 1e9; ++i)
        cnt[i] = (i - 1) * i ;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (a = 1; cnt[a + 1] <= n; ++a) ;
        b = n - cnt[a];
        if (n > 30) {
            printf("11");
            for (int i = 1; i <= a - 2; ++i)
                printf("3");
            for (int j = 1; j <= b ; ++j)
                printf("1");
            printf("337\n");
        }
        else {
            printf("133");
            for (int i = 1; i <= n; ++i)
                printf("7");
            printf("\n");
        }
    }
    return 0;
}