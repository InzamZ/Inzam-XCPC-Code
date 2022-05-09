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
int T = 1, n, m, x[maxn], ans = 0, ak;
vector<int>v;

signed main()
{
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n;
        ak = 0;
        v.clear();
        forr(i, 1, n) {
            scanf("%1lld", &x[i]);
            if (i == 1 || x[i] == x[i - 1])
                ++ak;
            else {
                v.push_back(ak);
                ak = 1;
            }
        }
        v.push_back(ak);
        for (int i = 0; i + 1 < v.size(); i++) {
            if (v[i] & 1ll) {
                ans++;
                v[i + 1]--;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}