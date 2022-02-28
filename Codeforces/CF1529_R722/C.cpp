#include <bits/stdc++.h>
using namespace std;
#define maxn 300010
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))
#define INF 0x3f3f3f3f

using ll = long long;

vector<int>e[maxn];
int ls[maxn], rs[maxn];
ll val[maxn][2], dp[maxn][2];
bool vis[maxn];

void dfs1(int rt)
{
    vis[rt] = true;
    for (int i = 0; i < e[rt].size(); ++i) {
        if (!vis[e[rt][i]] && ls[rt] == 0) {
            dfs1(e[rt][i]);
            ls[rt] = e[rt][i];
        }
        else if (!vis[e[rt][i]] && ls[rt] != 0) {
            dfs1(e[rt][i]);
            rs[rt] = e[rt][i];
        }
    }
}

void dfs2(int rt)
{
    int l = ls[rt], r = rs[rt];
    if (l == 0 && r == 0)
        return ;
    dfs2(l); dfs2(r);
    ll temp = 0;
    if (l != 0 && r != 0) {
        dp[rt][0] = max(dp[l][0] + abs(val[rt][0] - val[l][0]) + dp[r][0] + abs(val[rt][0] - val[r][0]), dp[l][0] + abs(val[rt][0] - val[l][0]) + dp[r][1] + abs(val[rt][0] - val[r][1]));
        temp = max(dp[l][1] + abs(val[rt][0] - val[l][1]) + dp[r][0] + abs(val[rt][0] - val[r][0]), dp[l][1] + abs(val[rt][0] - val[l][1]) + dp[r][1] + abs(val[rt][0] - val[r][1]));
        dp[rt][0] = max(dp[rt][0], temp);
        temp = 0;
        dp[rt][1] = max(dp[l][0] + abs(val[rt][1] - val[l][0]) + dp[r][0] + abs(val[rt][1] - val[r][0]), dp[l][0] + abs(val[rt][1] - val[l][0]) + dp[r][1] + abs(val[rt][1] - val[r][1]));
        temp = max(dp[l][1] + abs(val[rt][1] - val[l][1]) + dp[r][0] + abs(val[rt][1] - val[r][0]), dp[l][1] + abs(val[rt][1] - val[l][1]) + dp[r][1] + abs(val[rt][1] - val[r][1]));
        dp[rt][1] = max(dp[rt][1], temp);
    }
    else if (l == 0 ) {
        dp[rt][0] = max( dp[r][0] + abs(val[rt][0] - val[r][0]), dp[r][1] + abs(val[rt][0] - val[r][1]));
        dp[rt][1] = max( dp[r][0] + abs(val[rt][1] - val[r][0]),  dp[r][1] + abs(val[rt][1] - val[r][1]));
    }
    else if (r == 0) {
        dp[rt][0] = max( dp[l][0] + abs(val[rt][0] - val[l][0]), dp[l][1] + abs(val[rt][0] - val[l][1]));
        dp[rt][1] = max( dp[l][0] + abs(val[rt][1] - val[l][0]),  dp[l][1] + abs(val[rt][1] - val[l][1]));
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
        for (int i = 1; i <= n; ++i) {
            if (e[i].size() <= 2) {
                rt = i;
                break;
            }
        }
        dfs1(rt);
        dfs2(rt);
        cout << max(dp[rt][0], dp[rt][1]) << '\n';
        for (int i = 1; i <= n; ++i) {
            e[i].clear();
            ls[i] = rs[i] = 0;
            dp[i][0] = dp[i][1] = 0;
            vis[i] = false;
        }
    }
    return 0;
}