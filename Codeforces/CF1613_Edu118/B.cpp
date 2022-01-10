//Author: InzamZ

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define IF(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define DF(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 2e5 + 10;
const int maxb = 510;
const int inf = 1e9;
const ll Inf = 1e18;

bool flag = false;
int T = 1, n, mn, mnid;
int a[maxn];

int main()
{
    scanf("%d", &T);
    while (T--) {
        int cnt = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        mn = a[1];
        mnid = 1;
        for (int i = 2; i <= n; ++i) {
            if (a[i] < mn) mnid = i, mn = a[i];
        }
        for (int i = 1; i <= n; ++i) {
            if (cnt == n / 2) break;
            if (mnid != i && mn != a[i]) {
                ++cnt;
                printf("%d %d\n", a[i], mn);
            }
        }
    }
    return 0;
}