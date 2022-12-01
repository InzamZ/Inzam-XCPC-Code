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
int T = 1, n, m, x, ansx = 0, ansy;
vector<int>e[maxn], v;
string s;

bool checkit1(int id) {
    int cnt;
    cout << "? " << 1 << ' ' << id << ' ' << 1 << ' ' << n << endl;
    fflush(stdout);
    cin >> cnt;
    return cnt == id;
}

bool checkit2(int id) {
    int cnt;
    cout << "? " << 1 << ' ' << n  << " " << 1 << ' ' << id << ' ' << endl;
    fflush(stdout);
    cin >> cnt;
    return cnt == id;
}

int solve() {
    cin >> n;
    int l = 0, r = n;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (checkit1(mid))
            l = mid;
        else
            r = mid;
    }
    ansx = r;
    l = 0, r = n;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (checkit2(mid))
            l = mid;
        else
            r = mid;
    }
    ansy = r;
    cout << "! " << ansx << " " << ansy << endl;
    return 0;
}

signed main() {
    FIO;
    // cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}