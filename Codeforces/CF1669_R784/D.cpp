//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("/out.txt" , "w", stdout);
const int maxn = 1e5 + 10;
int T = 1, n, ans = 0;
string s;
int main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 1;
        int lcnt = -1; bool ok = 0;
        cin >> n;
        cin >> s;
        s = "W" + s + "W";
        for (int i = 0; i <= n + 1; ++i) {
            if (s[i] == 'W' && lcnt - i != -1) {
                lcnt = i;
                if (ok) {
                    ok = 0; continue;
                }
                else {
                    ans = 0; break;
                }
            }
            else if (s[i] == 'W')
                lcnt = i;
            else if (i && s[i - 1] != 'W' && s[i - 1] != s[i])
                ok = 1;
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}