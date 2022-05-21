//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0, a[maxn], b[maxn];
vector<int> v;

int solve() {
    ans = 0;
    cin >> n;
    f(i, 1, n) {
        cin >> a[i];
        v.push_back(a[i]);
        b[a[i]]++;
    }
    ans = n * (n - 1) * (n - 2) / 6;
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    f(i, 0, v.size() - 1) {
        ans -= b[v[i]] * (b[v[i]] - 1) / 2 * (n - b[v[i]]);
        ans -= b[v[i]] * (b[v[i]] - 1) * (b[v[i]] - 2) / 6;
    }
    cout << ans << '\n';
    return 0;
}

signed main() {
    FIO;
    // cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}