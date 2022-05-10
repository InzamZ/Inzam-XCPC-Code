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
int T = 1, n, m, x, ans = 0, tmp;
string s[maxn];
signed main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = -1;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> s[i];
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                tmp = 0;
                for (int k = 0; k < m; ++k)
                    tmp += abs(s[i][k] - s[j][k]);
                if (ans == -1 || ans > tmp)
                    ans = tmp;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}