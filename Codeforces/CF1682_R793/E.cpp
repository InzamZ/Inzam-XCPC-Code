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
vector<pii >ve;
map<pii, int>mp;
queue<pii >q, q2;

int solve() {
    ans = 0;
    cin >> n >> m;
    ve.clear();
    mp.clear();
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        mp[ {u, v}] = i;
        ve.push_back(make_pair(u, v));
    }
    sort(ve.begin(), ve.end());
    for (int i = 1; i <= n; ++i) {
        int u = a[i], v = i;
        if (u > v)
            swap(u, v);
        auto tmp = lower_bound(ve.begin(), ve.end(), make_pair(u, v));
        if (tmp != ve.end() && tmp->first == u && tmp->second == v) {
            q2.push(make_pair(u, v));
            break;
        }
    }
    auto tmp = q2.front();
    q2.pop();
    q.push(tmp);
    while (!q.empty()) {
        auto tmp = q.front();
        q.pop();
        int u = tmp.first, v = tmp.second;
        if (mp[ {u, v}] == -1)
            continue;
        cout << mp[tmp] << ' ';
        mp[tmp] = -1;
        swap(a[u], a[v]);
        if (a[u] == u) {
            u = v;
            v = a[v];
            if (u > v)
                swap(u, v);
            auto tmp = lower_bound(ve.begin(), ve.end(), make_pair(u, v));
            if (tmp != ve.end() && tmp->first == u && tmp->second == v)
                q.push(make_pair(u, v));
        }
        else {
            u = u;
            v = a[u];
            if (u > v)
                swap(u, v);
            auto tmp = lower_bound(ve.begin(), ve.end(), make_pair(u, v));
            if (tmp != ve.end() && tmp->first == u && tmp->second == v)
                q.push(make_pair(u, v));
        }
        if (q.empty()) {
            if (q2.empty())
                break;
            auto tmp = q2.front();
            q2.pop();
            if (a[tmp.first] == tmp.second && a[tmp.second] == tmp.first) {
                q.push(tmp);
                break;
            }
        }
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