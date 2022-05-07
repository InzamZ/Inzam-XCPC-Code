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
int T = 1, n, rt;
vector< vector<int> >ans;
vector<int>e[maxn], tmp;
int dfs(int u, int f)
{
    bool flag = false;
    for (auto v : e[u]) {
        if (v == f)
            continue;
        if (flag) {
            ans.push_back(tmp);
            tmp.clear();
        }
        tmp.push_back(v);
        dfs(v, u);
        flag = true;
    }
    return 0;
}
int main()
{
#ifdef FI
    FFF;
#endif
    FIO;
    cin >> T;
    while (T--) {
        ans.clear();
        cin >> n;
        for (int i = 1; i <= n; ++i)
            e[i].clear();
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x != i + 1)
                e[x].push_back(i + 1);
            else
                rt = x;
        }
        tmp.push_back(rt);
        dfs(rt, rt);
        if (!tmp.empty()) {
            ans.push_back(tmp);
            tmp.clear();
        }
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i].size() << '\n';
            for (int j = 0; j < ans[i].size(); ++j)
                cout << ans[i][j] << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}