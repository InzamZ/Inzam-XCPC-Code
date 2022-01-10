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

int point[maxn][2];
map<pii, int>mp;

int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}

void ins(int x, int y)
{
    bool flag;
    if (x == 0)
        flag = true;
    flag = (x / abs(x) * y) < 0;
    int xygcd;
    if (flag) {
        x = abs(x);
        y = -abs(y);
        xygcd = gcd(x, -y);
    }
    else {
        x = abs(x);
        y = abs(y);
        xygcd = gcd(x, y);
    }
    mp[pii(x / xygcd, y / xygcd)]++;
}

int main()
{
    int T = 1, n, all;
    ll ans = 0;
    // T = _read();
    while (T--) {
        ans = 0;
        scanf("%d", &n);
        all = (n - 1) * n / 2;
        for (int i = 1; i <= n; ++i)
            scanf("%d %d", &point[i][0], &point[i][1]);
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j)
                ins(point[i][0] - point[j][0], point[i][1] - point[j][1]);
        }
        for (auto it = mp.begin(); it != mp.end(); ++it)
            ans += (all - (*it).second) * (*it).second;
        printf("%lld\n", ans / 2);
    }
    return 0;
}