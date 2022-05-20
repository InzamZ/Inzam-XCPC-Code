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
int T = 1, n, l, r, ans = 0, a[maxn];
pii b[maxn];
vector<int>v;

int solve() {
    ans = 0;
    cin >> n;
    v.clear();
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]].first = 1e7;
        b[a[i]].second = 0;
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 1; i <= n; i++) {
        l = max(1ll, i - a[i] + 1 ) + a[i] - 1;
        r = min(n, i + a[i] - 1);
        if (b[a[i]].second == 0 || b[a[i]].second >= l) {
            b[a[i]].first = min(l, b[a[i]].first);
            b[a[i]].second = max(r, b[a[i]].second);
        }
        else {
            ans += b[a[i]].second - b[a[i]].first + 1;
            b[a[i]].first = l;
            b[a[i]].second = r;
        }
    }
    for (auto i : v)
        ans += b[i].second - b[i].first + 1;
    cout << ans << '\n';
    return 0;
}

signed main() {
    FIO;
    cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}