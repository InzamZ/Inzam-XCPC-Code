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
int id0, id1;
string s;
int main()
{
#ifdef FI
    FFF;
#endif
    FIO;
    cin >> T;
    while (T--) {
        cin >> s;
        ans = s.size();
        id1 = 0;
        id0 = ans - 1;
        for (int i = 0; i < ans; ++i) {
            if (s[i] == '1')
                id1 = i;
            if (s[i] == '0' && id0 == ans - 1)
                id0 = i;
        }
        // cout << id0 << ' ' << id1 << '\n';
        cout << min(ans, id0 - id1 + 1) << '\n';
    }
    return 0;
}