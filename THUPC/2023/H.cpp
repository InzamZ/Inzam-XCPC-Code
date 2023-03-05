//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0, a[maxn], b[maxn], pre[maxn];
vector<int>e[maxn], v;
string s;
int solve() {
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]]++;
        b[0] = max(b[0], a[i]);
    }
    pre[0] = 0;
    for (int i = 1; i <= b[0]; ++i)
        pre[i] = pre[i - 1] + b[i];
    int maj = 0;
    for (int i = n; i >= 1;) {
        while (i > 0 && a[i] <= maj)
            --i;
        if (i == 0)
            break;
        // cout << i << ' ' << pre[b[0]] - pre[maj] << endl
        ans += (i * (pre[b[0]] - pre[maj]));
        ++maj;
    }
    cout << ans << '\n';
    return 0;
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}