#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;
int main()
{
    int T = 1, n;
    // scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", 4 + 3 * n);
        printf("%d %d\n", 1, 1);
        for (int i = 0; i <= n; ++i) {
            int cur = i + 1;
            printf("%d %d\n", cur + 1, cur + 1);
            printf("%d %d\n", cur, cur + 1);
            printf("%d %d\n", cur + 1, cur);
        }
    }
    return 0;
}