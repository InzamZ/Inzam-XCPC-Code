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
int T = 1, n = 1, m, x, ans = 0, a[maxn], b[maxn];
vector<int>e[maxn], v;
string s;

int solve1() {
    ++n;
    cout << "SOLUTION FOR " << n << '\n';
    for (int i = (1ll << n) - 1; i >= 0 ; i--) {
        int cnt = 1;
        ans = (1 + n) * n / 2;
        v.clear();
        for (int j = 0; j < n; j++) {
            if (i & (1ll << j)) {
                cnt *= (j + 1);
                ans -= (j + 1);
                v.push_back(j + 1);
            }
        }
        if (ans == cnt) {
            for (auto x : v)
                cout << x << ' ';
            cout << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}

int solve() {
    cin >> n;
    if (n == 2 || n == 4)
        cout << -1 << '\n';
    else if (n == 3) {
        cout << 1 << '\n';
        cout << 3 << '\n';
    }
    else {
        cout << 3 << '\n';
        cout << 1 << ' ' << (n - 1) / 2 << ' ' << (n / 2) * 2 << '\n';
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