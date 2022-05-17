//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0, a[maxn][2], b[maxn];
vector<int>e[maxn], v;
string s[2];

int solve() {
    ans = 0;
    int i = 1;
    cin >> n;
    cin >> s[0] >> s[1];
    s[0] = '0' + s[0];
    s[1] = '0' + s[1];
    while (n >= 1 && s[0][n] == '.' && s[1][n] == '.')
        n--;
    while (i <= n && s[0][i] == '.' && s[1][i] == '.')
        ++i;
    a[i - 1][0] = a[i - 1][1] = 0;
    for (i; i <= n; i++) {
        if (s[0][i] == '*' && s[1][i] == '*')
            a[i][1] = a[i][0] = min(a[i - 1][0], a[i - 1][1]) + 2;
        else if (s[0][i] == '*') {
            a[i][0] = min(a[i - 1][0] + 1, a[i - 1][1] + 2);
            a[i][1] = min(a[i - 1][0] + 2, a[i - 1][1] + 2);
        }
        else if (s[1][i] == '*') {
            a[i][0] = min(a[i - 1][0] + 2, a[i - 1][1] + 2);
            a[i][1] = min(a[i - 1][0] + 2, a[i - 1][1] + 1);
        }
        else {
            a[i][0] = min(a[i - 1][0] + 1, a[i - 1][1] + 2);
            a[i][1] = min(a[i - 1][0] + 2, a[i - 1][1] + 1);
        }
    }
    if (n)
        cout << min(a[n][0], a[n][1]) - 1 << '\n';
    else
        cout << 0 << '\n';
    return 0;
}

signed main() {
    FIO;
    cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}