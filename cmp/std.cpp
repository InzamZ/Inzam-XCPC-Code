// freopen("data.in", "r", stdin);
// freopen("std.out", "w", stdout)；
#include <bits/stdc++.h>
using namespace std;
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;
#define pii pair<int,int>
#define pdd pair<double,double>

const double pi = acos(-1.0);
const ll inf = 1e18;
const int maxn = 3010;
int a[maxn], cnt[maxn][maxn];

int T = 1, n, q, l, r, k;
int ans = 1e7, c;

vector<int>v;

int main()
{
    freopen("data.in", "r", stdin);
    freopen("std.out", "w", stdout);
    v.push_back(1);
    v.push_back(2);
    for (int i = 3; i <= 500; ++i) {
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0)
                break;
            if ((j + 1) * (j + 1) > i)
                v.push_back(i);
        }
    }
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
            for (int j = 1; j < v.size(); ++j) {
                if (a[i] % v[j] == 0)
                    cnt[i][j] = cnt[i - 1][j] + 1;
                else
                    cnt[i][j] = cnt[i - 1][j];
            }
        }
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            int ans = 0;
            for (int j = 1; j < v.size(); ++j)
                ans = max(ans, cnt[i][j]);
            printf("%d\n", ans + 2);
            res = max(ans + 2, res);
        }
        printf("%d\n", res);
    }
    return 0;
}