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
int T = 1, n, m, x, ans = 0, a[maxn], b[maxn];
map<int, int>mp1, mp2;
vector<int>v;
string s;

int solve() {
    ans = 0;
    cin >> n;
    f(i, 1, n) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(a + 1, a + n + 1);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    f(i, 1, n) {
        mp1[a[i]] = -1;
        mp2[a[i]] = -1;
    }
    f(i, 1, n) {
        if (mp1[a[i]] == -1)
            mp1[a[i]] = i - 1;
    }
    F(i, n, 1) {
        if (mp2[a[i]] == -1)
            mp2[a[i]] = n - i;
    }
    for (int i = 0; i < v.size() - 1; ++i) {
        if (v[i] + 1 < v[i + 1]) {
            if (ans < min(mp1[v[i + 1]], mp2[v[i]])) {
                ans = min(mp1[v[i + 1]], mp2[v[i]]);
                x = v[i] + 1;
            }
        }
        else 
        {
            if (ans < min(mp1[v[i]], mp2[v[i + 1]])) {
                ans = min(mp1[v[i]], mp2[v[i + 1]]);
                x = v[i + 1];
            }
        }
    }
    cout << ans << ' ' << x << '\n';
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