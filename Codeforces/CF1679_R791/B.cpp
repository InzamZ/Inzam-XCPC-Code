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
int T = 1, n, m, q, ans = 0, lst2 = -1, a[maxn], b[maxn];

int solve() {
    ans = 0;
    m = 0;
    
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ans += a[i];
        b[i] = 0;
    }
    for (int i = 1; i <= q ; ++i) {
        int op, x, y;
        cin >> op;
        if (op == 1) {
            cin >> x >> y;
            if (b[x] > lst2)
                ans += (y - m - a[x]);
            else
                ans += (y - m);
            b[x] = i;
            a[x] = y - m;
        }
        else {
            lst2 = i;
            cin >> x;
            m = x;
            ans = n * x;
        }
        cout << ans << '\n';
    }
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