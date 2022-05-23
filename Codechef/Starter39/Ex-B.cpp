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
priority_queue<int>e[30];
string s;

int solve() {
    ans = 0;
    int cnt = 0;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        if (i == n - 1 || s[i + 1] != s[i]) {
            cnt++;
            ans = max(ans, cnt);
            e[s[i] - 'a'].push(cnt);
            cnt = 0;
        }
        else
            cnt++;
    }
    cout << ans << ' ';
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; j++) {
            if (e[j].size() == 1)
                ans = max(ans, e[j].top());
            else if (e[j].size() < 1)
                continue;
            else {
                int tmp = e[j].top(); e[j].pop();
                tmp += e[j].top(); e[j].pop();
                e[j].push(tmp);
                ans = max(ans, tmp);
            }
        }
        cout << ans;
        if (i == n)
            cout << '\n';
        else
            cout << ' ';
    }
    for (int i = 0; i < 26; i++)
        while (e[i].size())
            e[i].pop();
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