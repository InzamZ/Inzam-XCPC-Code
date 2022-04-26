//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, x, y;
ll a[maxn], ans = 0;
vector<vector<int>>v;
vector<int>v1;
int main()
{
#ifdef FI
    FFF;
#endif
    FIO;
    // cin >> T;
    while (T--) {
        ans = 0;
        int cnt = 0, l, r;
        v.clear();
        cin >> n >> x >> y;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (y <= a[i] && a[i] <= x)
                v1.push_back(a[i]);
            else {
                v.push_back(v1);
                v1.clear();
            }
        }
        if (v1.size() > 0)
            v.push_back(v1);
        for (auto it : v) {
            l = r = 0;
            int len = r - l + 1, cntx = 0, cnty = 0;
            while (l < it.size()) {
                while (r < it.size() && (cntx == 0 || cnty == 0)) {
                    if (it[r] == x)
                        ++cntx;
                    if (it[r] == y)
                        ++cnty;
                    ++r;
                }
                if (cntx && cnty)
                    ans += (it.size() - r + 1);
                if (it[l] == x)
                    --cntx;
                if (it[l] == y)
                    --cnty;
                ++l;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}