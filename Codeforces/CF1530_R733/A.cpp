#include <bits/stdc++.h>
using namespace std;
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;
#define pii pair<int,int>
#define pdd pair<double,double>

int T = 1, h, w, cur = 0, a;
ll ans = 1e18, c;

int main()
{
    scanf("%d", &T);
    while (T--) {
        cur = 0;
        scanf("%d", &a);
        while (a) {
            cur = max(cur,a % 10);
            a /= 10;
        }
        printf("%d\n", cur);
    }
    return 0;
}