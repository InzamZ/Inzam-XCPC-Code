//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, ans = 0;
string tmp[20] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f", "g", "17", "18", "19"};
int main()
{
#ifdef FI
    FFF;
#endif
    FIO;
    // cin >> T;
    while (T--) {
        ans = 0;
        cin >> n;
        string s = "1";
        for (int i = 1; i < n; ++i)
            s = s + tmp[i + 1] + s;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] > '9' || s[i] < '0')
                cout << '1' << s[i] - 'a';
            else
                cout << s[i];
            if (i != s.size() - 1)
                cout << ' ';
            else
                cout << '\n';
        }
    }
    return 0;
}