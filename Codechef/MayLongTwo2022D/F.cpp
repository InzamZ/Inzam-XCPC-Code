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
    int cnt = 0;
    for (int i = 0; i < 34; i++) {
        b[i] = 0;
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt = 0;
        while (a[i]) {
            if (a[i] % 2 == 1) 
                b[cnt]++;
            a[i] >>= 1;
            cnt++;
        }
    }
    for (int i = 0; i < 34; i++) {
        if (b[i])
            ans++;
    }
    cout << ans << '\n';
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