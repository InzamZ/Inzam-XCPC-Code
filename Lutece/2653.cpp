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
    int T = 1, n, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &k);
        n /= k;
        if (n % 2 == 1)
            printf("Kate\n");
        else
            printf("Draw\n");
    }
    return 0;
}