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
    while (T--) {
        ans = 0;
        string s;
        cin >> s;
        if (s.size() == 1) {
            cout << "Bob" << ' ';
            cout << s[0] - 'a' + 1 << '\n';
            continue;
        }
        else {
            cout << "Alice" << ' ';
            for (int i = 0; i < s.length(); ++i)
                ans += (s[i] - 'a' + 1) ;
            if (s.length() % 2 == 1)
                ans = max(ans - s[0] + 'a' - 1 - s[0] + 'a' - 1, ans - s[s.length() - 1] + 'a' - 1 - s[s.length() - 1] + 'a' - 1);
            cout << ans << '\n';
        }
    }
    return 0;
}