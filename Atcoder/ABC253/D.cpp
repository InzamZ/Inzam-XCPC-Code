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
int T = 1, n, m, x, ans = 0, a, b;

int solve() {
    ans = 0;
    cin >> n >> a >> b;
    ans = n * (n + 1) / 2;
    x = n / a;
    ans -= (x + 1) * a * x / 2;
    x = n / b;
    ans -= (x + 1) * b * x / 2;
    x = n / (a * b / __gcd(a, b));
    ans += (x + 1) * (a * b / __gcd(a, b)) * x / 2;
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