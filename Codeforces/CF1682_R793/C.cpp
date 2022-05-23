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
int T = 1, n, m, x, ans = 0, a[maxn], b[maxn], cnt[maxn];
vector<int>e[maxn], v;
string s;

int solve() {
    ans = 0;
    cin >> n;
    v.clear();
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        v.push_back(a[i]);
        cnt[i] = 0;
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 1; i <= n; ++i)
        b[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    for (int i = 1; i <= n; ++i) {
        cnt[b[i]]++;
        if (cnt[b[i]] > 2)
            cnt[b[i]] = 2;
    }
    for (int i = 1; i <= v.size(); ++i)
        ans += cnt[i];
    cout << (ans + 1) / 2 << '\n';
    for (int i = 1; i <= n; ++i) {
        cnt[i] = 0;
    }
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