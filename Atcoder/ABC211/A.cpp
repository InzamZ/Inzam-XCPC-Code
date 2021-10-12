// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// #define pii pair<int,int>
// #define pll pair<ll,ll>
// #define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
// #define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

// const int maxn = 2e5 + 10;
// const int maxb = 110;
// const int inf = 1e9;
// const ll mod = 1e9 + 7;

// vector<int>e[maxn];
// ll cnt[maxn], len[maxn], ans;
// bool vis[maxn];

// struct node {
//     ll len;
//     int idx;
// };

// queue<int>q;
// queue<node>p;

// int main()
// {
//     int T = 1, n, m;
//     // scanf("%d",&T);
//     while (T--) {
//         scanf("%d %d", &n, &m);
//         for (int i = 1; i <= m; ++i) {
//             int u, v;
//             scanf("%d %d", &u, &v);
//             e[u].push_back(v);
//             e[v].push_back(u);
//         }
//         len[1] = cnt[1] = 1;
//         q.push(1);
//         while (!q.empty()) {
//             int res = q.front(); q.pop();
//             vis[res] = 1;
//             for (int i = 0; i < e[res].size(); ++i) {
//                 if (vis[e[res][i]] == 0) {
//                     len[e[res][i]] = len[res] + 1;
//                     q.push(e[res][i]);
//                 }
//             }
//         }
//         if (len[n]) {
//             p.push(node{1ll, 1});
//             while (!p.empty()) {
//                 node res = p.front(); p.pop();
//                 vis[res.idx] = 1;
//                 if (res.len > len[res.idx])
//                     continue;
//                 for (int i = 0; i < e[res.idx].size(); ++i) {
//                     if (len[e[res.idx][i]] == res.len + 1)
//                         cnt[e[res.idx][i]] += cnt[res.idx];
//                     cnt[e[res.idx][i]] %= mod;
//                 }
//             }
//         }
//         printf("%lld\n", cnt[n] % mod);
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 2e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll mod = 1e9 + 7;

char imap[10][10];
bool vis[10][10];
ll ans = 0, mcur = 0, mcur2 = 0;
map<string, int>exi;
map<string, int>vis;
int T = 1, n, m;

void hashit1()
{
    char s[70];
    int cur = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            s[cur++] = imap[i][j];
    string s1 = s;
    if (exi.count(s1) == 0) {
        exi[s1] = ++mcur;
        ans++;
    }
}

void hashit2()
{
    char s[70];
    int cur = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            s[cur++] = imap[i][j];
    string s1 = s;
    if (exi.count(s1) == 0) {
        vis[s1] = ++mcur1;
        ans++;
    }
}

void dfs(int dep)
{
    if (x == 0 || y == 0 || x == n + 1 || y == n + 1)
        return ;
    vis[x][y] = 1;
    imap[x][y] = '@';
    if (dep == m ) {
        hashit();
        imap[x][y] = '.';
        vis[x][y] = 0;
        return ;
    }
    if (imap[x - 1][y] == '.' && !vis[x - 1][y])
        dfs(x - 1, y, dep + 1);
    if (imap[x ][y - 1] == '.' && !vis[x][y - 1])
        dfs(x, y - 1, dep + 1);
    if (imap[x + 1][y] == '.' &&  !vis[x + 1][y])
        dfs(x + 1, y, dep + 1);
    if (imap[x][y + 1] == '.' &&  !vis[x][y + 1])
        dfs(x, y + 1, dep + 1);
    imap[x][y] = '.';
    vis[x][y] = 0;
}

int main()
{
    // scanf("%d",&T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i)
            scanf("%s", imap[i] + 1);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) {
                if (imap[i][j] == '.')
                    dfs(i, j, 1);
            }
        printf("%lld\n", ans);
    }
    return 0;
}