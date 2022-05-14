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
const int maxn = 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0, a[maxn], b[maxn];
vector<int>e[maxn], v;
char s[maxn][maxn];

int solve() {
    ans = 0;
    cin >> n >> m;
    int mx = -1, my = -1;
    f(i, 0, n - 1) {
        scanf("%s", s[i]);
    }
    f(i, 0, n - 1) {
        f(j, 0, m - 1) {
            if (s[i][j] == 'R') {
                if (mx == -1) {
                    mx = i;
                    my = j;
                }
                else {
                    mx = min(mx, i);
                    my = min(my, j);
                }
            }
        }
    }
    if (s[mx][my] == 'R')
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}

signed main() {
    // FIO;
    cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}