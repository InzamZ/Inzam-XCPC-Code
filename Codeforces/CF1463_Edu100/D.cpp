#include <bits/stdc++.h>
using namespace std;
#define maxn 2000010

int num[maxn], used[maxn];

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--) {
        int mx = 0, mn = 0, sp = 0;
        scanf ("%d", &n);
        memset(used, 0, (sizeof(int)) * (n * 2 + 1));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &num[i]);
            used[num[i]] = 1;
        }
        for (int i = 1; i <= 2 * n; i++) {
            if (used[i])
                sp++;
            else
                sp--;
            mn = min(mn, sp);
            mx = max(mx, sp);
        }
        printf("%d\n", n - (mx - mn) + 1);
    }
    return 0;
}
