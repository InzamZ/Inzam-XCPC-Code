#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

using ll = long long;
const int maxn = 5e5 + 5;
const int MAXB = 528;
const int inf = 1e9;
const ll Inf = 1e18;

struct node {
    int x, y;
};

node t[maxn];
int ans[MAXB+10][MAXB+10], a[maxn];
int p[maxn][3], cur = 0;

int main()
{
    int T = 1, n;
    // scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d %d", &p[i][0], &p[i][1], &p[i][2]);
            if (p[i][0] == 2 && p[i][1] <= MAXB) {
                ++cur;
                t[cur].x = p[i][1];
                t[cur].y = p[i][2];
            }
        }
        int ncur = 1;
        for (int i = 1; i <= n; ++i) {
            if (p[i][0] == 1) {
                a[p[i][1]] += p[i][2];
                for (int j = 1; j <= MAXB; ++j)
                    ans[j][p[i][1] % j] += p[i][2];
            }
            else if (p[i][0] == 2 && p[i][1] <= MAXB) {
                printf("%d\n", ans[p[i][1]][p[i][2]]);
                ncur++;
            }
            else if (p[i][0] == 2 && p[i][1] >MAXB) {
                ans[0][0] = 0;
                for (int j = p[i][2]; j <= maxn - 5; j += p[i][1])
                    ans[0][0] += a[j];
                printf("%d\n", ans[0][0]);
            }
        }
    }
    return 0;
}