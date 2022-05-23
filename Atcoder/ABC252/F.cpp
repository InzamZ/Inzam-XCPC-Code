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
priority_queue<int>q;

int solve() {
    ans = 0;
    cin >> n >> m;
    ans = m;
    f(i, 1, n) {
        cin >> a[i];
        q.push(a[i]);
    }
    while (q.size() > 2) {
        int tmp = q.top();
        q.pop();
        int tmp2 = q.top();
        q.pop();
        ans += (tmp + tmp2);
        q.push(tmp + tmp2);
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