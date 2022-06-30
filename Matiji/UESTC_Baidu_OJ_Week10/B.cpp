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
int T = 1, n, m, ans = 0;
int x[maxn], y[maxn];
bool visx[maxn], visy[maxn], flag = 0;
vector<int>e1[maxn];
vector<int>e2[maxn];

int dfs(int val, int tp) {
    if (tp == 1) {
        if (visx[val]) return 0;
        visx[val] = 1;
        for (auto y : e1[val]) {
            if (!visy[y])
                dfs(y, 2);
        }
    }
    else {
        if (visy[val]) return 0;
        visy[val] = 1;
        for (auto x : e2[val]) {
            if (!visx[x])
                dfs(x, 1);
        }
    }
    return 0;
}

int solve() {
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
        e1[x[i]].push_back(y[i]);
        e2[y[i]].push_back(x[i]);
    }
    dfs(x[1], 1);
    for (int i = 2; i <= n ; ++i) {
        if (!visx[x[i]]){
            ++ans;
            dfs(x[i], 1);
            // dfs(y[i], 2);
        }
    }
    cout << ans << endl;
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