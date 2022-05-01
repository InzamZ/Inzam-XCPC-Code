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
    FIO;
    cin >> T;
    while (T--) {
        ans = 1;
        int cnt[30], tmp = 0;
        for (int i = 0; i < 30; ++i)
            cnt[i] = 0;
        string s;
        cin >> s;
        for (auto x : s) {
            if (cnt[x - 'a'] == 0)
                tmp++;
            cnt[x - 'a']++;
        }
        if (tmp == 1)
            ans = 1;
        else {
            bool f[30];
            for (int i = 0; i < 30; ++i)
                f[i] = false;
            for (int i = 0; i < s.size() - tmp; ++i) {
                if (i < tmp && f[s[i] - 'a']) {
                    ans = 0; break;
                }
                else if (i < tmp)
                    f[s[i] - 'a'] = true;
                if (s[i] != s[i + tmp]) {
                    ans = 0; break;
                }
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}