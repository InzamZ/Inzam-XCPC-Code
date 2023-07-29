//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int maxn = 1e5 + 10;
const int maxb = 110;
int T = 1, n, m, ans = 0, a[maxn], b[maxn], cnta[maxn], cntb[maxn];
vector<pii>e1[maxn], e2[maxn];
vector<int> v;
int x, y, w;
string s;

// 单源最短路
void dijkstra(int s, int *a, int *cnta, vector<pii> *e) {
    cnta[s] = 1;
    priority_queue<pii, vector<pii>, greater<pii>>q;
    vector<int>vis(n + 1, 0);
    q.push({0, s});
    while (!q.empty()) {
        pii t = q.top();
        q.pop();
        if (vis[t.second])
            continue;
        vis[t.second] = 1;
        for (auto i : e[t.second]) {
            if (a[i.first] > a[t.second] + i.second) {
                a[i.first] = a[t.second] + i.second;
                q.push({a[i.first], i.first});
                cnta[i.first] = cnta[t.second];
            }
            else if (a[i.first] == a[t.second] + i.second)
                cnta[i.first] += cnta[t.second];
        }
    }
}

int solve() {
    ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> w;
        e1[x].push_back({y, w});
        e2[y].push_back({x, w});
    }
    memset(a, 0x3f, sizeof(a));
    memset(b, 0x3f, sizeof(b));
    a[1] = b[n] = 0;
    dijkstra(1, a, cnta, e1);
    dijkstra(n, b, cntb, e2);
    for (int i = 1; i <= n; i++) {
        // cout << "i: " << a[i] << ' ' << b[i] << ' ' << cnta[i] << ' ' << cntb[i] << '\n';
        if (a[i] + b[i] == a[n] && cnta[i] * cntb[i] == cnta[n])
            v.push_back(i);
    }
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++) {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    return 0;
}
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
    return 0;
}