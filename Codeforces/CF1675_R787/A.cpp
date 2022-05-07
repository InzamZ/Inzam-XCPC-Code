//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, ans = 0;
int main()
{
#ifdef FI
    FFF;
#endif
    FIO;
    cin >> T;
    int a, b, c, x, y;
    while (T--) {
        ans = 0;
        cin >> a >> b >> c >> x >> y;
        if (x + y > a + b + c)
            cout << "No\n";
        else if (x + y <= a + b + c) {
            c -= max(0, x - a);
            c -= max(0, y - b);
            if (c >= 0)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    return 0;
}