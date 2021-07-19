#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e5;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
int a[maxn], b[maxn], c[maxn];

int main()
{
    int T = 1, n;
    int bmx = -1, amx = -1;
    // scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            printf("? %d %d\n", 0, i);
            fflush(stdout);
            scanf("%d", &c[i]);
            if (i != 0 && c[i] != n && c[i - 1] == n) {
                bmx = i - 1;
                break;
            }
            else if (i != 0 && c[i] == n && c[i - 1] != n) {
                bmx = i;
                break;
            }
            else if ( i != 0 && c[i - 1] == n ) {
                amx = 0; break;
            }
        }
        if (bmx != -1) {
            int res = (bmx + 1) % n ;
            for (int i = 0; i < n; ++i) {
                printf("? %d %d\n", i, res);
                fflush(stdout);
                scanf("%d", &c[i]);
                if (c[i] == n) {
                    amx = i;
                    break;
                }
            }
        }
        else {
            int res = 1;
            for (int i = 0; i < n; ++i) {
                printf("? %d %d\n", 1, i);
                fflush(stdout);
                scanf("%d", &c[i]);
                if (c[i] == n) {
                    bmx = i;
                    break;
                }
            }
        }
        printf("! %d\n", (bmx - amx + n) % n);
        fflush(stdout);
    }
    return 0;
}