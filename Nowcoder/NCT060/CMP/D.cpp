//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod (998244353ll)

#define pii pair<int,int>
#define pll pair<ll,ll>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, ans = 0, a, b;
int inv6, inv2;

int inv(int x, int m)
{
    int res = 1, tmp = x;
    while (m) {
        if (m & 1ll)
            res = (res * tmp) % mod;
        m >>= 1;
        tmp = (tmp * tmp) % mod;
    }
    return res;
}

int f1(int x)
{
    return ( ( (x * (x + 1)) % mod) * ( (2 * x + 1) % mod) % mod) * inv6 % mod;
}

signed main()
{
    FIO;
    cin >> T;
    inv6 = inv(6, mod - 2);
    inv2 = inv(2, mod - 2);
    while (T--) {
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        ans = f1(a - 1) - f1(b);
        ans = (ans + mod) % mod;
        ans = ans + (((a + b) % mod) * ((a + b) % mod) * inv2 % mod) * ((b - a + 1 + mod) % mod) % mod;
        ans %= mod;
        ans -= ((a * b) % mod) * (b - a + 1) % mod;
        ans = (ans + mod) % mod;
        cout << ans << '\n';
    }
    return 0;
}