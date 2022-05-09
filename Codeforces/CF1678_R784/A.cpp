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
int vis[maxn];
int a[maxn];
signed main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        bool ok = 0;
        cin >> n;
        forr(i, 0, 100) {
            vis[i] = 0;
        }
        forr(i, 1, n) {
            cin >> a[i];
            vis[a[i]]++;
            if (vis[a[i]] >= 2)
                ok = 1;
        }
        ans = n + 1;
        if (vis[0])
            ans = n -  vis[0];
        else if (ok)
            ans = n;
        cout << ans << '\n';
    }
    return 0;
}