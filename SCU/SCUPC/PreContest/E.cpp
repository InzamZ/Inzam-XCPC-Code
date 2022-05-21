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
    int ansy, ansx;
    if (n > m) {
        ansy = m / 2;
        if (m % 2 == 1)
            ansx = n - m / 2 - 1;
        else
            ansx = m / 2 - 1;
    }
    else {
        if (n % 2 == 1) {
            ansx = n / 2;
            ansy = m - 1 - n / 2;
        }
        else {
            ansx = n / 2 - 1;
            ansy = n / 2;
        }
    }
    cout << ansx << ' ' << ansy << '\n';
    return 0;
}

signed main() {
    FIO;
    // cin >> T;
    while (cin >> n >> m) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}