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
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, ans = 0, m;
int main()
{
#ifdef FI
    FFF;
#endif
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n >> m;
        m--; n--;
        if (m == 0 && n > 1) {
            cout << -1 << '\n';
            continue;
        }
        if (n == 0 && m > 1) {
            cout << -1 << '\n';
            continue;
        }
        ans = min(m, n) * 2;
        m = max(m, n) - min(m, n);
        ans += m / 2 * 4;
        if (m % 2)
            ans += 1;
        cout << ans << '\n';
    }
    return 0;
}