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
int T = 1, n;
queue<pair<ll, ll>>q;
int main()
{
#ifdef FI
    FFF;
#endif
    FIO;
    // cin >> T;
    while (T--) {
        ll ans = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            ll op, x, y;
            cin >> op;
            if (op == 1) {
                cin >> x >> y;
                q.push(pair<ll, ll>(x, y));
            }
            else {
                ans = 0;
                cin >> x;
                while (x > 0) {
                    if (q.front().second == x) {
                        ans += q.front().second * q.front().first;
                        q.pop();
                        break;
                    }
                    else if (q.front().second > x) {
                        q.front().second -= x;
                        ans += q.front().first * x;
                        break;
                    }
                    else {
                        x -= q.front().second;
                        ans += q.front().second * q.front().first;
                        q.pop();
                    }
                }
                cout << ans << '\n';
            }
        }
    }
    return 0;
}