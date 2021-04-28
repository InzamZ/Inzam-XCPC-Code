#include <bits/stdc++.h>
#include <cmath>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], b[maxn], tms[maxn], dep[maxn], arr[maxn];

using ll = long long;

int main()
{
    int t, n, ans = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d %d", &a[i], &b[i]);
        for (int i = 1; i <= n; i++)
            scanf("%d", &tms[i]);
        for (int i = 1; i <= n; i++) {
            arr[i] = dep[i - 1] + (a[i] - b[i - 1] + tms[i]);
            dep[i] = max(b[i], arr[i] + (b[i] - a[i] + 1) / 2);
        }
        printf("%d\n", arr[n]);
    }
    return 0;
}