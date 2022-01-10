//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
#define FREAD 1

const int maxn = 1e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 1e9 + 7;

int a[4] = {8, 3, 45, 100};

int main()
{
    int T = 1, n, ans = 0, k, ansn, ansm;
    // scanf("%d", &T);
    while (T--) {
        scanf("%d", &k);
        ansn = k * 4, ansm = 2 * k;
        printf("%d %d\n", ansn, ansm);
        for (int i = 1; i <= k; ++i)
            printf("%d %d ", 8, 3);
        for (int i = 1; i <= k; ++i)
            printf("%d %d%c", 45, 100, i == k ? '\n' : ' ');
        for (int i = 1; i <= 2 * k; ++i)
            printf("%d ", i);
        for (int i = 1; i <= 2 * k; ++i)
            printf("%d%c", i, i == 2 * k ? '\n' : ' ');
    }
    return 0;
}