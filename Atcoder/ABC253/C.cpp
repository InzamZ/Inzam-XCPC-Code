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
map<int, int>mp;
set<int>s1, s2;

int solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            cin >> x;
            if (s1.count(-x) == 0) {
                s1.insert(-x);
                s2.insert(x);
                mp[x] = 1;
            }
            else
                mp[x]++;
        }
        else if (op == 2) {
            cin >> x >> m;
            if (mp[x] > m)
                mp[x] -= m;
            else {
                s1.erase(-x);
                s2.erase(x);
                mp[x] = 0;
            }
        }
        else
            cout << -(*s1.upper_bound(-2000000000ll)) - (*s2.upper_bound(-1)) << '\n';
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