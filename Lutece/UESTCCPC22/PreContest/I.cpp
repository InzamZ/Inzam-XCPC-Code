//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x = 0, ans = 0, a[maxn], b[maxn];
vector<int>e[maxn],v;
string s;
int solve() {
    int cnt = 0;
    ans++;
    for (int x = 0; x * 8 <= ans; x++) {
        for (int y = 0; x * 8 + y * 9 <= ans; y++) {
            for (int z = 0; x * 8 + y * 9 + z * 10 <= ans; z++) {
                if (x * 8 + y * 9 + z * 10 == ans) {
                    cnt++;
                }
            }
        }
    }
    if (cnt == 0) {
        x = max(x, ans);
    }
    cout << ans << ": " <<cnt << endl;
    return 0;
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> T;
    while (T--) {
    // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    cout << x << endl;
    return 0;
}