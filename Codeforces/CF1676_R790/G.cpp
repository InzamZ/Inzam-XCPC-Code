//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define pii pair<int,int>
#define forr(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0, sumb, sumw, cnt;
vector<int>e[maxn];
string str;

int dfs(int rt, int &sumb, int &sumw)
{
    int ans = 0;
    int sb = sumb, sw = sumw, c = cnt;
    if (str[rt - 1] == 'B')
        sumb++;
    else
        sumw++;
    for (auto i : e[rt]) {
        ans += dfs(i, sumb, sumw);
    }
    if (sumb - sb == sumw - sw)
        ++ans;
    return ans;
}
signed main()
{
    FIO;
    cin >> T;
    while (T--) {
        sumb = sumw = ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            e[i].clear();
        for (int i = 2; i <= n; i++) {
            cin >> x;
            e[x].push_back(i);
        }
        cin >> str;
        cout << dfs(1, sumb, sumw) << '\n';
    }
    return 0;
}