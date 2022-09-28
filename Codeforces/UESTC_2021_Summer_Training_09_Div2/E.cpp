#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 5e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

string s[maxn];

int main()
{
    int T = 1, n, ans = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    // scanf("%d", &T);
    while (T--) {
        ans = 0;
        // scanf("%d", &n);
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> s[i];
        for (int i = n - 1; i >= 1; --i) {
            if (s[i] <= s[i + 1])
                continue;
            else {
                string temp = s[i];
                int siz = min(s[i].size(), s[i + 1].size());
                for (int j = 0; j < siz; ++j) {
                    if (temp[j] > s[i + 1][j]) {
                        s[i] = temp.substr(0, j);
                        break;
                    }
                    if (j == siz - 1)
                        s[i] = s[i + 1];
                }
            }
        }
        for (int i = 1; i <= n; ++i)
            cout << s[i] << '\n';
    }
    return 0;
}
