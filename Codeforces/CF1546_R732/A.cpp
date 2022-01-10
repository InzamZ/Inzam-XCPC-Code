#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))
using ll = long long;

const int maxn = 1e2 + 5;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

int a[maxn], b[maxn];

int main()
{
    int T = 1, n, cnt = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        cnt = a[0] = b[0] = 0;
        F(i, 1, n) {
            scanf("%d", &a[i]);
            a[0] += a[i];
        }
        F(i, 1, n) {
            scanf("%d", &b[i]);
            b[0] += b[i];
            cnt += abs(a[i] - b[i]);
        }
        if (a[0] != b[0])
            printf("-1\n");
        else {
            printf("%d\n", cnt / 2);
            int i = 1, j = 1;
            while (i <= n && j <= n) {
                while (a[i] - b[i] <= 0 && i <= n)
                    ++i;
                while (a[j] - b[j] >= 0 && j <= n)
                    ++j;
                if (i > n || j > n)
                    break;
                int l = min(a[i] - b[i], b[j] - a[j]);
                a[i] -= l; a[j] += l; cnt += l;
                F(t, 1, l)  printf("%d %d\n", i, j);
            }
        }
    }
    return 0;
}