//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("/out.txt" , "w", stdout);
const int maxn = 1e5 + 10;
ll T = 1, n, ans = 0, a, b;
int main()
{
    FIO
#ifdef LOCAL
    freopen("./out.txt", "w", stdout);
#endif
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> a >> b;
        if (a % 2 == 0) {
            a /= 2;
            // for (int i=1;i<=a;++i) cout << '1';
            // for (int i=1;i<=b;++i) cout << '0';
            // for (int i=1;i<=a;++i) cout << '1';
            ans = a * a * b - a * b;
        }
        else {
            a /= 2;
            // cout << '1';
            // for (int i=1;i<=a;++i) cout << '1';
            // for (int i=1;i<=b;++i) cout << '0';
            // for (int i=1;i<=a;++i) cout << '1';
            ans = (a + 1) * a * b - a * b;
        }
        cout << ans << '\n';
    }
    return 0;
}