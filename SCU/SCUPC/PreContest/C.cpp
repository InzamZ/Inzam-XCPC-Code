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

class FenwickTree {
  public:
    int n, ta[maxn], tb[maxn];
    int lowbit(int x) {
        return x & (-x);
    }
    void update(int i, int val) {
        int x = i;
        while (i <= n) {
            tb[i] += val;
            ta[i] = abs(tb[i]);
            i += lowbit(i);
        }
    }
    int getsum(int i) {
        int res = 0, x = i;
        while (i > 0) {
            res += ta[i];
            i -= lowbit(i);
        }
        return res;
    }
};

int solve() {
    ans = 0;
    cin >> n;
    FenwickTree ft;
    ft.n = n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ft.update(i, a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        ft.update(i, a[i - 1] - a[i]);
        cout << ft.getsum(n) - ft.getsum(i) << ' ';
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