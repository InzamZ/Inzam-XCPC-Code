#include <bits/stdc++.h>
using namespace std;
#define maxn 300010
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))
#define INF 0x3f3f3f3f

using ll = long long;

vector<int>e[maxn];
ll val[maxn][2], dp[maxn][2];

void dfs2(int rt,int p)
{
    ll temp;
    for (auto r: e[rt])
    {
        if (r==p) continue;
        dfs2(r,rt);
        temp = max( dp[r][0] + abs(val[rt][0] - val[r][0]), dp[r][1] + abs(val[rt][0] - val[r][1]));
        dp[rt][0] += temp;
        temp = max( dp[r][0] + abs(val[rt][1] - val[r][0]), dp[r][1] + abs(val[rt][1] - val[r][1]));
        dp[rt][1] += temp;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    int T, n, rt;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> val[i][0] >> val[i][1];
        for (int i = 2; i <= n; i++) {
            int a, b;
            cin >> a >> b;
            e[a].push_back(b);
            e[b].push_back(a);
        }
        dfs2(1,0);
        cout << max(dp[1][0], dp[1][1]) << '\n';
        for (int i = 1; i <= n; ++i) {
            e[i].clear();
            dp[i][0] = dp[i][1] = 0;
        }
    }
    return 0;
}
