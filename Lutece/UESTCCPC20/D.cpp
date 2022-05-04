//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define pii pair<int,int>
#define pll pair<ll,ll>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, ans = 0, m;
struct N {
    int val, base, times;
    N(int v): val(v)
    {
        base = val;
        times = 1;
        while (base % 3 == 0 && base / 3 != 0) {
            base /= 3;
            times *= 3;
        }
    }
    N() {}
};
N v[maxn];
int a[maxn];
signed main()
{
    FIO;
    while (T--) {
        ans = 0;
        cin >> n >> m;
        a[0] = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            v[i] = N(x);
            a[i] = a[i - 1] + v[i].times;
        }
        for (int i = 1; i <= m; ++i) {
            int q;
            cin >> q;
            ans = lower_bound(a + 1, a + 1 + n, q) - a;
            cout << v[ans].base;
            if (i != m)
                cout << ' ';
            else
                cout << '\n';
        }
    }
    return 0;
}