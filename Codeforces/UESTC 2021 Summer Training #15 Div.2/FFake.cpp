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

int a[maxn], cnt = 0;
int G[maxn];

int T = 1, n, ans = 0, m;
bool check(int x, int y)
{
    bool result = 1;
    for (int i = 1; i <= n; ++i) {
        if (__gcd(a[i], a[y]) != 1 && G[i] == G[x]) {
            result = 0;
            return false;
        }
    }
    return true;
}

int main()
{
    // scanf("%d",&T);
    while (T--) {
        ans = 0;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; ++i) {
            if (G[i])
                continue;
            cnt++;
            G[i] = cnt;
            for (int j = i + 1; j <= n; ++j) {
                if (G[j] == 0 && check(i, j))
                    G[j] = cnt;
            }
        }
        printf("%d\n", cnt);
        for (int i = 1; i <= n; ++i)
            printf("%d%c", G[i], i == n ? '\n' : ' ');
    }
    return 0;
}