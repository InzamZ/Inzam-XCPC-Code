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
int T = 1, n, m, x = 0, ans = 0, a[maxn], b[maxn];
vector<int>e[maxn], v;
string s;

int solve() {
    ans = 0;
    cin >> s >> n;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == 'F')
            ans++;
    }
    if (n <= s.length() - ans) {
        ans = 0;
        for (int i = 0; n && i < s.length(); ++i) {
            if (s[i] == 'T')
                x++;
            else {
                if (x % 2 == 1) {
                    --n;
                    ans++;
                }
                x = 0;
                ans++;
            }
        }
        ans += (n / 2);
        cout << ans << endl;
    }
    else if ((n + ans - s.length()) % 2 == 0)
        cout << s.length() << endl;
    else
        cout << s.length() - 1 << endl;
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