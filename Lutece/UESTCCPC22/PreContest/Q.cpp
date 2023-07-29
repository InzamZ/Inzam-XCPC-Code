//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, ansmin = 1, ansmax = 1, a, b;
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a >> b;
        ansmin = min(ansmin, max(1ll, a - 1));
        ansmax = max(ansmax, b - 1);
    }
    cout << ansmin << ' ' << ansmax << '\n';
    return 0;
}