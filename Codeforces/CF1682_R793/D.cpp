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
int T = 1, n, m, rt, ans = 0, a[maxn], b[maxn];
vector<int>e[maxn], v;
string s;

int solve() {
    ans = 0;
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            a[i] = 1;
            ans++;
        }
        else
            a[i] = 0;
        b[i] = (i - 1 + n) % n;
    }
    if (ans % 2 == 1 || ans == 0)
        cout << "NO\n";
    else {
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                b[(i + 1) % n] = (i + 1) % n;
                rt = (i + 1) % n;
                break;
            }
        }
        for (int i = 1; i <= n - 1; ++i) {
            int cur = (rt + i) % n;
            if (a[cur] == 1)
                b[(cur + 1) % n] = rt;
        }
        cout << "YES" << '\n';
        for (int i = 0; i < n; ++i) {
            if (rt != i)
                cout << i + 1 << ' ' << b[i] + 1 << '\n';
        }
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