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
int T = 1, n, m, x, y, ans = 0;
int f1[maxn], f2[maxn];
int imap[300][300];
signed main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n >> m;
        for (int i = 0; i <= 1000; i++)
            f1[i] = f2[i] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                cin >> imap[i][j];
                int xx = imap[i][j];
                f1[i - j + 200] += xx;
                f2[i + j] += xx;
                if (f1[0] < f1[i - j + 200])
                    f1[0] = f1[i - j + 200];
                if (f2[0] < f2[i + j])
                    f2[0] = f2[i + j];
            }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                ans = max(f1[i - j + 200] + f2[i + j] - imap[i][j], ans);
        }
        cout << ans << '\n';
    }
    return 0;
}