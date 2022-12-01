#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxn = 2e6 + 10;
int T = 1, n, m, v, ansplus = 0, ansxor = 0, num[maxn], premax[maxn];

signed main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m >> v;
    for (int i = 1; i <= n ; ++i) {
        cin >> num[i];
        if (i == 1)
            premax[i] = num[i] + v;
        else
            premax[i] = max(premax[i - 1], num[i]) + v;
    }
    for (int i = 1; i <= m ; ++i) {
        int x, k, ans = 0, tmp;
        cin >> x >> k;
        if (n - x + 1 < k)
            ans = 0;
        else {
            if (x != 1)
                ans = premax[x - 1] + v;
            else
                ans = 0;
            for (int j = x + 1; j <= x + k - 1; ++j)
                ans = max(num[j] + 1, ans) + v;
            ans -= (v * k);
        }
        ansxor ^= ans;
        ansplus += ans;
    }
    cout << ansxor << " " << ansplus << '\n';
    return 0;
}