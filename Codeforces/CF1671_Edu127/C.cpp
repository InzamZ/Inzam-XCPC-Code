//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("/out.txt" , "w", stdout);
const int maxn = 2e5 + 10;
ll T = 1, n, x, xx, ans = 0;
ll v[maxn], c[maxn];

bool check(ll day, ll no, ll val)
{
    return xx >= val + (no * day);
}

int main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        ll cur = 0, tmp = 0;
        cin >> n >> x;
        xx = x;
        for (int i = 1; i <= n; ++i)
            cin >> v[i];
        sort(v + 1, v + n + 1);
        for (int i = 1; i <= n; ++i) {
            if (x >= v[i]) {
                ++cur;
                x -= v[i];
            }
        }
        ans = cur;
        for (int i = 1; i <= cur; ++i) {
            tmp += v[i];
            int l = 0, r = xx + 1, mid;
            while (l + 1 < r) {
                mid = (l + r) >> 1;
                if (check(mid, i, tmp))
                    l = mid;
                else
                    r = mid;
            }
            c[i] = l;
        }
        // for (int i = 0; i <= cur; ++i)
        //     cout << c[i] << ' ';
        // cout << '\n';
        c[cur + 1] = 0;
        for (int i = 1; i <= cur; ++i)
            ans += (c[i] - c[i + 1]) * i;
        cout << ans << '\n';
    }
    return 0;
}