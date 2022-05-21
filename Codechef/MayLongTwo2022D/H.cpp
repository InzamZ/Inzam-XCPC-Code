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
#define mod (1000000007ll)
int T = 1, n, m, x, ans = 0, a[maxn], b[10][2];
string s;

int solve() {
    ans = 0;
    cin >> n;
    for (int j = 0; j < 7; j++)
        b[j][0] = b[j][1] = 0;
    b[0][0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int cnt = 1, tmp = a[i];
        while (tmp) {
            tmp /= 10;
            cnt *= 10;
        }
        for (int j = 0; j < 7; j++) {
            tmp = (j * cnt + a[i]) % 7;
            b[tmp][1] = b[tmp][0] + b[j][0];
        }
        for (int j = 0; j < 7; j++)
            b[j][0] = b[j][1] % mod;
    }
    cout << b[0][0] - 1 << '\n';
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