//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define pii pair<int,int>
#define forr(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0;
int a[maxn];
signed main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (i == 1)
                m = a[i];
            else
                m = min(a[i], m);
        }
        for (int i = 1; i <= n; i++) {
            ans += (a[i] - m);
        }
        cout << ans << '\n';
    }
    return 0;
}