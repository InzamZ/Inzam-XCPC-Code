//Author: InzamZ
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define IF(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define DF(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e5 + 10;
const int maxb = 10;
const int inf = 1e9;
const ll Inf = 1e18;

bool flag = true;
int T = 1, n, ans = 0;
int d[maxn][10], c1, c2;

int main()
{
    scanf("%d", &T);
    while (T--) {
        flag = true;
        scanf("%d", &n);
        IF(i, 1, n) scanf("%d %d %d %d %d", &d[i][1], &d[i][2], &d[i][3], &d[i][4], &d[i][5]);
        IF(i, 1, 5) {
            IF(j, i + 1, 5) {
                if (i == j) continue;
                flag = true;
                c1 = c2 = 0;
                IF(k, 1, n) {
                    if (!flag) break;
                    if (!d[k][i] && !d[k][j]) flag = false;
                    else if (d[k][i] && !d[k][j]) ++c1;
                    else if (!d[k][i] && d[k][j]) ++c2;
                }
                if (2 * c1 > n || 2 * c2 > n) flag = false;
                if (flag) break;
            }
            if (flag) break;
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}