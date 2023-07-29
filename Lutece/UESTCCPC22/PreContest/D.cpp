//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, siz, ans1 = 0, ans2 = 1, a[maxn], b[maxn];
vector<pii>v[maxn];
int solve() {
    siz = ans1 = 0;
    ans2 = 1;
    cin >> n;
    int x1, x2, y1, y2;
    for (int i = 1; i <= n; ++i) {
        cin >> x1 >> y1 >> x2 >> y2;
        v[x1 + y1].push_back({x1, x2});
        siz = max(siz, x1 + y1);
    }
    for (int i = 1; i <= siz; ++i) {
        if (v[i].empty())
            continue;
        sort(v[i].begin(), v[i].end());
        int l = -1, r = -1;
        for (auto j : v[i]) {
            if (l == -1) {
                l = j.first;
                r = j.second;
            }
            else if (j.first < r) {
                ans2 = 0;
                r = max(r, j.second);
            }
            else {
                ans1 += (r - l);
                l = j.first;
                r = j.second;
            }
        }
        v[i].clear();
        ans1 += (r - l);
    }
    if (ans2)
        cout << "YES\n";
    else
        cout << "NO\n";
    cout << ans1 << '\n';
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
    return 0;
}