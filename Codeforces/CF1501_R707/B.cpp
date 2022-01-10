#include <bits/stdc++.h>
#include <cmath>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn], dra[maxn];

using ll = long long;

int main()
{
    int t, n, ans = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            dra[i] = 0;
        }
        for (int i = 1; i <= n; i++)
            dra[max(1, i - a[i] + 1)] = min(a[i], i);
        for (int i = 1, cnt = 0; i <= n; i++, cnt--) {
            cnt = max(cnt, dra[i]);
            if (cnt)
                printf("1 ");
            else
                printf("0 ");
        }
        putchar('\n');
    }
    return 0;
}