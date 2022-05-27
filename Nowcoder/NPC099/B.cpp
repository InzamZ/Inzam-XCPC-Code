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
int T = 1, a, b, c, d, c1, c2, c3, c4, ans;
vector<int>e[maxn], v;
string s;

int solve() {
    ans = 4e18;
    cin >> a >> b >> c >> d;
    cin >> c1 >> c2 >> c3 >> c4;
    //case1
    int cnt = 0;
    if (a >= c) {
        cnt += c1 * c;
        cnt += c2 * (a - c);
        cnt += c4 * b;
    }
    else 
    {
        cnt += c1 * a;
        cnt += c3 * (c - a);
        cnt += c4 * d;
    }
    ans = min(ans, cnt);

    //case2
    cnt = 0;
    if (a >= d) {
        cnt += c2 * d;
        cnt += c1 * (a - d);
        cnt += c3 * b;
    }
    else 
    {
        cnt += c2 * a;
        cnt += c4 * (d - a);
        cnt += c3 * c;
    }

    //case3
    cnt = 0;
    if (b >= d) {
        cnt += c4 * d;
        cnt += c3 * (b - d);
        cnt += c1 * a;
    }
    else 
    {
        cnt += c4 * b;
        cnt += c2 * (a - c);
        cnt += c1 * c;
    }
    ans = min(ans, cnt);

    //case4
    cnt = 0;
    if (b >= c) {
        cnt += c3 * c;
        cnt += c4 * (b - c);
        cnt += c2 * a;
    }
    else 
    {
        cnt += c3 * b;
        cnt += c1 * (c - b);
        cnt += c2 * d;
    }
    ans = min(ans, cnt);

    cout << ans << '\n';
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