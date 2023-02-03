//InzamZ
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
const int maxn = 1e6 + 10;
const int maxb = 110;
int T = 1, n, m, k, ans = 0, fa[maxn], b[maxn], siz[maxn];
vector<int>v[maxn];
vector<int>v2[maxn];
vector<int>v1;
pii v3[maxn];

int dfs(int rt, int f) {
    fa[rt] = f;
    siz[rt] = 1;
    for (auto t : v[rt]) {
        if (t == f)
            continue;
        siz[rt] += dfs(t, rt);
    }
    if (rt != f && v[rt].size() == 1) {
        v1.push_back(rt);
        v2[f].push_back(rt);
        ans++;
    }
    return siz[rt];
}

int solve() {
    ans = 0;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 1);
    v3[0] = {0, 0};
    if (n == 2)
        cout << "NO" << endl;
    else if (n == 1)
        cout << "NO" << endl;
    else if (ans % 2 == 1) {
        int v3len = 0;
        for (int i = 1; i <= n; ++i) {
            if (v2[i].size() == 0)
                continue;
            v3len++; v3[v3len] = {v2[i].size(), i};
        }
        sort(v3 + 1, v3 + v3len + 1);
        int bla = ans / 2;
        bool ok = 0;
        for (int i = 1; !ok && i <= v3len; ++i ) {
            auto t = v3[i];
            v3[i].first = 0;
            if ( (siz[ t.second ] == t.first + 1) && bla && bla >= t.first ) {
                b[ t.second ] = 1;
                for (auto t2 : v2[ t.second ]) {
                    b[t2] = 1;
                    --bla;
                }
                ok = 1;
            }
        }
        for (int _ = 1; _ <= v3len; ++_ ) {
            auto t = v3[_];
            if (t.first == 0)
                continue;
            if (bla > 0) {
                b[t.second] = 0;
                for (auto t2 : v2[t.second]) {
                    if (bla)
                        b[t2] = 1;
                    else
                        b[t2] = 0;
                    --bla;
                }
            }
            else {
                b[t.second] = 1;
                for (auto t2 : v2[t.second])
                    b[t2] = 0;
            }
        }
        if (ok == 0)
            cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++)
                cout << b[i] << ' ';
        }
    }
    else {
        bool flag = 0;
        for (auto t : v2) {
            for (auto t1 : t) {
                b[t1] = flag;
                b[fa[t1]] = !flag;
                flag = !flag;
            }
        }
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++)
            cout << b[i] << ' ';
    }
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