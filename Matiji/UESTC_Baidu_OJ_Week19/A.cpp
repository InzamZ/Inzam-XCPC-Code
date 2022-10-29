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
vector<int>e[maxn], v;
string s;

int solve() {
    ans = 0;
    cin >> n;
    a[0] = 2;
    a[1] = a[2] = 1;
    for (int i = 3; a[i - 1] < n; ++i) {
        a[0]++; a[i] = a[i - 1] + a[i - 2];
    }
    F(i, a[0], 1) {
        if (n == 0)
            break;
        if (a[i] <= n) {
            n -= a[i];
            ++ans;
        }
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