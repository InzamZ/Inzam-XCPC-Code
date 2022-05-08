//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define pii pair<int,int>
#define forr(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, a, b,  ans = 0;
signed main()
{
    FIO;
    // cin >> T;
    while (T--) {
        ans = 0;
        cin >> n >> m;
        cin >> a >> b;
        ans = 4;
        if (a == n)
            --ans;
        if (b  == m)
            --ans;
        if (a == 1)
            --ans;
        if (b == 1)
            --ans;
        cout << ans << '\n';
    }
    return 0;
}