//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0, a[maxn], pre[maxn];
vector<int>e[maxn], v;
string s;
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    ans = 0, x = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > x) {
            ans += (a[i] - x) / (pre[i - 1] + 1);
            x += (a[i] - x) / (pre[i - 1] + 1) * (pre[i - 1] + 1);
            if (x < a[i]) {
                ++ans;
                x += pre[i - 1] + 1;
            }
        }
        x += a[i];
    }
    cout << ans << '\n';
    return 0;
}