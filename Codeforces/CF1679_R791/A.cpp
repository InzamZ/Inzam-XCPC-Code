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
    if (n % 2 == 1) {
        ans = -1;
        cout << ans << '\n';
    }
    else if (n == 2) {
        ans = -1;
        cout << ans << '\n';
    }
    else {
        n /= 2;
        if (n % 3 == 0)
            cout << n / 3 << ' ';
        else if (n % 3 == 1)
            cout << n / 3 + 1 << ' ';
        else
            cout << n / 3 + 1 << ' ';
        cout << n / 2 << '\n';
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