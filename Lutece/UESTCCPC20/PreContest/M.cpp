//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n;

ll ta[maxn], num[maxn], id[maxn];

ll lowbit(ll x)
{
    return x & (-x);
}

void update(ll i, ll val)
{
    ll x = i;
    while (i <= n) {
        ta[i] += val;
        i += lowbit(i);
    }
}

ll getsum(ll i)
{
    ll res = 0, x = i;
    while (i > 0) {
        res += ta[i];
        i -= lowbit(i);
    }
    return res;
}

vector<int>e[maxn];
ll ans[maxn][3];

void dfs(int u)
{
    ll a = getsum(num[u] - 1); ll b = getsum(num[u]) - a; ll c = getsum(n) - b - a;
    for (int v : e[u])
        dfs(v);
    ans[u][0] = getsum(num[u] - 1) - a;
    ans[u][1] = getsum(num[u]) - b - getsum(num[u] - 1);
    ans[u][2] = getsum(n) - c - getsum(num[u]);
    update(num[u], 1);
}

int main()
{
    FIO;
    while (T--) {
        cin >> n;
        for (int i = 2; i <= n; i++) {
            int x;
            cin >> x;
            e[x].push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            cin >> num[i];
            id[i] = num[i];
        }
        sort(id + 1, id + n + 1);
        for (int i = 1; i <= n; i++)
            num[i] = lower_bound(id + 1, id + n + 1, num[i]) - id;
        dfs(1);
        for (int i = 1; i <= n; i++)
            cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << '\n';
    }
    return 0;
}