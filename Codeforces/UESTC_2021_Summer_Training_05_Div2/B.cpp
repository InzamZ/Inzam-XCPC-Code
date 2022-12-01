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
int a[maxn], id[maxn];
int cnt = 0;
int T = 1, n, mn, res1, res2;

int main()
{
    // freopen("data.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    scanf("%d", &T);
    while (T--) {
        bool flag = true;
        cnt = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            id[a[i]] = i;
        }
        for (int i = n; i >= 1; --i) {
            if (id[i] == n)
                break;
            if (id[i] == 1) {
                flag = false;
                break;
            }
        }
        if (n == 1)
            printf("YES\n");
        else
            printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}