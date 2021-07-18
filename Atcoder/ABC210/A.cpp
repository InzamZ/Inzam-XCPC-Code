#include <bits/stdc++.h>
using namespace std;
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;
#define pii pair<int,int>
#define pdd pair<double,double>

const double pi = acos(-1.0);
const int maxn = 1e6 + 10;
const int inf = 1e9;
const ll Inf = 1e18;
// struct point {
//     double x, y;
// } p[maxn];
ll T = 1, n, a, b, cost = 0, c;

int main()
{
    // freopen("data.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    // scanf("%lld", &T);
    while (T--) {
        bool flag = true;
        scanf("%lld %lld %lld %lld", &n, &a, &b, &c);
        if (n >= a)
            printf("%lld\n", a * b + (n - a)*c);
        else
            printf("%lld\n", n * b);
    }
    return 0;
}