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
int T = 1, n, m, k, ans = 0, a[maxn], b[maxn];
vector<pii>e[maxn];
vector<int>v;
string s;

int dfs(int rt, int flag, int fa) {
    int cnt = 1;
    for (auto &i : e[rt]) {
        if (i.first == fa)
            continue;
        if (!flag && i.second == 1)
            cnt += dfs(i.first, 1, rt);
        else if (flag == 1)
            cnt += dfs(i.first, 2, rt);
        else
            cnt += dfs(i.first, flag, rt);
    }
    if (flag == 1)
        v.push_back(cnt);
    return cnt;
}

int solve() {
    ans = 0;
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        e[u].push_back({v, x});
        e[v].push_back({u, x});
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= n; ++i)
        e[i].clear();
    for (auto &i : v)
        ans += i;
    if (ans + k < n)
        cout << -1 << '\n';
    else {
        sort(v.begin(), v.end(), greater<int>());
        int len = 0;
        while (n > k)
            n -= v[len++];
        cout << len << '\n';
    }
    v.clear();
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