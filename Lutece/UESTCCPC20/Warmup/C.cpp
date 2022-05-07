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
int T = 1, n, ans = 0, d, cnt = 1;
int a[maxn];
int main()
{
#ifdef FI
    FFF;
#endif
    FIO;
    // cin >> T;
    while (T--) {
        ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (a[i])
                cnt = i;
            if (i - cnt >= d) {
                ++ans;
                cnt = i;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}