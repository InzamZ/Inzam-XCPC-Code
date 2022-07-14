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
const int maxn = 6e5 + 10;
const int maxb = 110;
int T = 1, k, x, y, l, r, t;
vector<int>e[maxn], v;
string s;


int solve() {
    bool ans = true;
    cin >> k >> l >> r >> t >> x >> y;
    if (x > y && k - t * (x - y) < l) ans = false;
    else if (x > y && k - t * (x - y) > l) ans = true;

    if (x + 1 == y && l + x <= r) ans = true;
    else if (x + 1 == y && l + x > r) ans = false;

    
    
    if (ans)
        cout << "Yes\n";
    else
        cout << "No\n";
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