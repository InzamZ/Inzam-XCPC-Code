#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
using ll = long long;
int d[maxn], a[maxn];
int main()
{
    int n, len, cnt;
    scanf("%d", &n);
    if (n == 0) {
        putchar('0');
        putchar('\n');
        return 0;
    }
    for (int i = 0; i <= n; ++i)
        scanf("%d", a + i);
    d[0] = a[0]; len = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] < a[0])
            continue;
        if (a[i] >= d[len])
            d[++len] = a[i];
        else {
            cnt = upper_bound(d + 1, d + len + 1, a[i]) - d;
            d[cnt] = a[i];
        }
    }
    printf("%d\n", len);
    return 0;
}