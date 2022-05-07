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
int T = 1, n, ans = 0, k;
string s;
queue<char> q;
int main()
{
#ifdef FI
    FFF;
#endif
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n >> k;
        cin >> s;
        while (!q.empty())
            q.pop();
        char a = 'a', l = 'a', r = 'a';
        for (int i = 0; i < n; ++i) {
            if (q.empty() || q.back() < s[i])
                q.push(s[i]);
        }
        while (!q.empty()) {
            if (k + 'a' >= q.front()) {
                a = q.front();
                q.pop();
            }
            else {
                k -= a - 'a';
                r = q.front();
                l = r - k;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (s[i] <= a)
                cout << 'a';
            else if (s[i] >= l && s[i] <= r)
                cout << l;
            else
                cout << s[i];
        }
        cout << '\n';
    }
    return 0;
}