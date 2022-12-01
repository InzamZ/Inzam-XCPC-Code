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
char s[maxn];
ll T = 1, n, a, b, cost = 0;

int main()
{
    // freopen("data.in", "r", stdin);
    // freopen("std.out", "w", stdout);
    scanf("%lld", &T);
    while (T--) {
        bool flag = true;
        int cnt = 0;
        scanf("%lld %lld %lld", &n, &a, &b);
        scanf("%s", s);
        cost = n * a + n * b + b;
        for (int i = 1; i < n - 1; ++i)
            if (s[i - 1] == s[i + 1] && s[i - 1] == 1)
                s[i] = '0';
        int i = 0, j = 0;
        while (s[j] == '0' && j < n)
            ++j;
        if (j == n) {
            printf("%lld\n", b + (a + b)*n); continue;
        }
        for (i; i < n;) {
            i = j;
            int cnt = 0;
            if (flag) {
                flag = false;
                cost += 2 * a;
            }
            while (s[i] == '1' && i < n)
                ++i;//i 4
            cost += b * (i - j + 1);
            j = i;
            while (s[j] == '0' && j < n)
                ++j;//j 6
            cnt = j - i;
            if (j == n)
                break;
            // cout << cnt << endl;
            if ((cnt - 1)*b > 2 * a)
                cost += 2 * a;
            else
                cost += (cnt - 1) * b;
        }
        printf("%lld\n", cost);
    }
    return 0;
}