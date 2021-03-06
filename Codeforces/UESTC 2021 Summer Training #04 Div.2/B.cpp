#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

int tra[maxn][3], a[maxn];
int distra[maxn];
int n, m, k, t, l, r, d;

bool check(int x)
{
    int res = a[m + 1 - x];
    for (int i = 0; i <= n; ++i)
        distra[i] = 0;
    for (int i = 1; i <= k; ++i) {
        if (res < tra[i][2]) {
            distra[tra[i][0] - 1] += 1;
            distra[tra[i][1]] -= 1;
        }
    }
    for (int i = 1; i <= n; ++i)
        distra[i] += distra[i - 1];
    int sumt = 0;
    for (int i = 0; i <= n; ++i)
        if (distra[i])
            sumt += 3;
        else ++sumt;
    return sumt <= t;
}

int main()
{
    scanf("%d %d %d %d", &m, &n, &k, &t);
    for (int i = 1; i <= m; ++i)
        scanf("%d", &a[i]);
    sort(a + 1, a + 1 + m);
    for (int i = 1; i <= k; ++i)
        scanf("%d %d %d", &tra[i][0], &tra[i][1], &tra[i][2]);
    l = 0, r = m + 1;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%d\n", l);
    return 0;
}