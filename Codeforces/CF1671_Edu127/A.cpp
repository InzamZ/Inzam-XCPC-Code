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
int main()
{
    FIO;
    cin >> T;
    while (T--) {
        string s;
        ans = 1;
        cin >> s;
        if (s.length() == 1) {
            cout << "NO" << '\n';
            continue;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (i == 0 ) {
                if (s[i] != s[i + 1]) {
                    ans = 0;
                    break;
                }
            }
            else if (i == s.length() - 1) {
                if (s[i] != s[i - 1]) {
                    ans = 0;
                    break;
                }
            }
            else if (i == 0) {
                if (s[i] != s[i - 1]) {
                    ans = 0;
                    break;
                }
            }
            else {
                if (s[i] != s[i - 1] && s[i] != s[i + 1]) {
                    ans = 0;
                    break;
                }
            }
        }
        if (ans)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}