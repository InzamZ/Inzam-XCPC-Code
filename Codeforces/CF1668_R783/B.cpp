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
int a[maxn];
signed main()
{
#ifdef FI
    FFF;
#endif
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        sort(a + 1, a + n + 1);
        m -= (a[n] * 2 + 1);
        for (int i = n - 1; i > 1; --i)
            m -= (a[i] + 1);
        if (m < 1)
            cout << "No" << '\n';
        else
            cout << "Yes" << '\n';
    }
    return 0;
}