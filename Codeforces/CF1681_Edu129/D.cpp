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
int T = 1, n, m, x, ans = -1, a[maxn], b[maxn];
vector<int>e[maxn], v;
map<int, int>mp;
string s;

int ch(int x) {
    int cnt = 0;
    while (x) {
        cnt ++;
        x /= 10;
    }
    return cnt;
}

void dfs(int u, int p) {
    if (mp.find(u) != mp.end() && mp[u] <= p)
        return ;
    if (ch(u) == n) {
        if (ans == -1 || ans > p)
            ans = p;
        return ;
    }
    if (ch(u) > n)
        return ;
    mp[u] = p;
    vector<int>tmp;
    int uu = u;
    while (uu) {
        tmp.push_back(uu % 10);
        uu /= 10;
    }
    sort(tmp.begin(), tmp.end());
    reverse(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for (auto bi : tmp)
        dfs(u * bi, p + 1);
    return ;
}
int solve() {
    cin >> n >> x;
    dfs(x, 0ll);
    cout << ans << "\n";
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