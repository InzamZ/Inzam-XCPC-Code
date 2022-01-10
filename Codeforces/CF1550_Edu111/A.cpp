#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;
const int maxn = 1e4 + 5;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

int s;

int main()
{
    int T = 1, n, cnt, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        cnt = 1; ans = 0;
        while (n > 0) {
            n -= cnt;
            cnt += 2;
            ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}