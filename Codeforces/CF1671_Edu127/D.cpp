//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("/out.txt" , "w", stdout);
const int maxn = 2e5 + 10;
ll T = 1, n, x, ans = 0;
ll v[maxn];
int main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n >> x;
        ll mx = -1e9, mn = 1e9;
        v[0] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> v[i];
            mx = max(mx, v[i]);
            mn = min(mn, v[i]);
            if (i != 1)
                ans += abs(v[i] - v[i - 1]);
        }
        if (n == 1)
            ans = max(x - 1, v[1] - 1);
        else {
            // for (int i = 1; i <= n; ++i) {
            //     if (i == 1) {
            //         flag[v[i]][0] = min(v[i + 1], flag[v[i]][0]);
            //         flag[v[i]][1] = max(v[i + 1], flag[v[i]][1]);
            //     }
            //     else if (i == n) {
            //         flag[v[i]][0] = min(v[i - 1], flag[v[i]][0]);
            //         flag[v[i]][1] = max(v[i - 1], flag[v[i]][1]);
            //     }
            //     else {
            //         flag[v[i]][0] = min(min(v[i - 1], v[i + 1]), flag[v[i]][0]);
            //         flag[v[i]][1] = max(max(v[i - 1], v[i + 1]), flag[v[i]][1]);
            //     }
            // }
            if (mn > 1) {
                ll tmp = 1e9;
                for (int i = 1; i <= n; ++i) {
                    if (i == 1)
                        tmp = min(tmp, v[i] - 1);
                    else if (i == n)
                        tmp = min(tmp, v[i] - 1);
                    else
                        tmp = min(tmp, 2 * (v[i] - 1));
                }
                ans = ans + tmp;
            }
            if (mx < x) {
                ll tmp = 1e9;
                for (int i = 1; i <= n; ++i) {
                    if (i == 1)
                        tmp = min(tmp, x - v[i]);
                    else if (i == n)
                        tmp = min(tmp, x - v[i]);
                    else
                        tmp = min(tmp, 2 * (x - v[i]));
                }
                ans = ans + tmp;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}