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
        ans = 0;
        cin >> n;
        cin >> s;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] <= s[i - 1] && s[i] != s[0]) ++ans;
            else break;
        }
        for (int i = 0; i <= ans; ++i) cout << s[i];
        for (int i = ans; i >= 0; --i) cout << s[i];
        cout << '\n';
    }
    return 0;
}