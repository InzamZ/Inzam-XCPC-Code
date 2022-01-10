//Author: InzamZ

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define IF(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define DF(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e5 + 10;
const int maxb = 510;
const int inf = 1e9;
const ll Inf = 1e18;

bool flag = false;
int T = 1, n, m, ans = 0;
string s;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            bool ok = 0;
            for (int j = i; j <= i + i - 1; ++j) {
                if (j >= n) {
                    if (s[i] <= s[i - 1]) {
                        ++cnt;
                        continue;
                    } else {
                        ok = 1;
                        break;
                    }
                }
                if (s[j] == s[2 * i - j - 1]) continue;
                if (s[j] > s[2 * i - j - 1]) ok = 1;
                if (s[j] < s[2 * i - j - 1] && i != j) {
                    ++cnt;
                } else if (s[j] < s[2 * i - j - 1] && i == j) {
                    if (s[i] <= s[i - 1]) {
                        ++cnt;
                        continue;
                    } else {
                        ok = 1;
                        break;
                    }
                }
                if (s[j] != s[2 * i - j - 1]) break;
                if (j == 2 * i - 1) ok = 1;
            }
            if (ok) break;
        }
        for (int i = 0; i <= cnt; ++i) cout << s[i];
        for (int i = cnt; i >= 0 ; --i) cout << s[i];
        cout << '\n';
    }
    return 0;
}