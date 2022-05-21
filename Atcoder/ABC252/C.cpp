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
string s[maxn];

int solve() {
    ans = 1e9;
    int tmp, cnt[15];
    cin >> n;
    f(i, 1, n) {
        cin >> s[i];
    }
    for (int i = 0; i <= 9; ++i) {
        f(j, 0, 9) cnt[j] = 0;
        tmp = 0;
        f(j, 1, n) {
            f(k, 0, 9) {
                if (s[j][k] == i + '0')
                {
                    tmp = max(tmp,k + cnt[k] *10);
                    cnt[k]++;
                }
            }
        }
        ans = min(ans, tmp);
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