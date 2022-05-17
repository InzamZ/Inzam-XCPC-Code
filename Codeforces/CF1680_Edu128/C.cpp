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
int T = 1, n, m, len, ans = 0, a[maxn], b[maxn], cnt0[maxn], cnt1[maxn];
vector<int>v;
string s;
pii p[maxn];

bool ck(int x) {
    x = cnt1[len] - x;
    int l = 0, ans = 0, r = s.size();
    if (x <= 1)
        return true;
    ans = cnt0[v[x - 1]] - cnt0[v[0]];
    for (int i = 0; i + x < v.size() - 1; i++)
        ans = min(cnt0[v[x + i]] - cnt0[v[i + 1]], ans);
    return ans <= cnt1[len] - x;
}

int solve() {
    cnt0[0] = cnt1[0] = ans = 0;
    cin >> s;
    v.clear();
    len = s.length();
    for (int i = len - 1; s[i] == '0' && i >= 0; i--)
        len--;
    if (s[0] == '0')
        cnt0[0] = 1;
    else {
        cnt1[0] = 1;
        v.push_back(0);
    }
    for (int i = 1; i < len; i++) {
        if (s[i] == '0') {
            cnt0[i] = cnt0[i - 1] + 1;
            cnt1[i] = cnt1[i - 1];
        }
        else {
            v.push_back(i);
            cnt1[i] = cnt1[i - 1] + 1;
            cnt0[i] = cnt0[i - 1];
        }
    }
    v.push_back(len);
    cnt0[len] = cnt0[len - 1];
    cnt1[len] = cnt1[len - 1];
    int l = -1, r = cnt1[len], mid;
    while (l + 1 < r) {
        mid = (l + r) >> 1;
        if (ck(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << '\n';
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
/*
5
101110110
1001001001001
0000111111
00000
1111
*/