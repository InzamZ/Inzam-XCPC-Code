//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define pii pair<int,int>
#define pll pair<ll,ll>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, ans = 0;
int a[maxn];
signed main()
{
    FIO;
    // cin >> T;
    while (T--) {
        ans = 0x7fffffffffffffff;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        for (int i = 1; i <= n; ++i) {
            int tmp = 0, lst = 0;
            for (int j = i + 1; j <= n; ++j)
                if ((lst + 1) % a[j] == 0) {
                    tmp += (lst + 1) / a[j];
                    lst = lst + 1;
                }
                else {
                    tmp += ((lst + 1) / a[j] + 1);
                    lst = ((lst + 1) / a[j] + 1) * a[j];
                }
            lst = 0;
            for (int j = i - 1; j >= 1 ; --j)
                if ((lst + 1) % a[j] == 0) {
                    tmp += (lst + 1) / a[j];
                    lst = lst + 1;
                }
                else {
                    tmp += ((lst + 1) / a[j] + 1);
                    lst = ((lst + 1) / a[j] + 1) * a[j];
                }
            ans = min(ans, tmp);
        }
        cout << ans << '\n';
    }
    return 0;
}