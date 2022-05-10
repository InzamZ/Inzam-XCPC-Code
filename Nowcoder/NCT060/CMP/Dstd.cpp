//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 1e6 + 10;
const int maxb = 110;
ll T = 1, n, ans = 0, m;
ll a[maxn];
int main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n >> m;
        // sum : -x^2+(a+b)x-ab
        for (int x = n; x <= m; ++x) {
            ans = ans - (x - n) * (x - m);
            ans += 998244353ll;
            ans %= 998244353ll;
        }
        cout << ans << '\n';
    }
    return 0;
}