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

vector<int>e[maxn];
ll cnt[maxn], len[maxn];
bool vis[maxn];

queue<int>q;

int main()
{
    int T = 1, n, ans = 0, m;
    // scanf("%d",&T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= m; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        len[1] = cnt[1] = 1;
        q.push(1);
        while (!q.empty()) {
            int res = q.front(); q.pop();
            vis[res] = 1;
            for (int i = 0; i < e[res].size(); ++i) {
                if (vis[e[res][i]] == 0) {
                    if (len[e[res][i]] == 0)
                        len[e[res][i]] = len[res] + 1;
                    if (cnt[e[res][i]] == 0)
                        q.push(e[res][i]);
                    if (len[res] + 1 == len[e[res][i]])
                        cnt[e[res][i]] += cnt[res];
                    cnt[e[res][i]] %= mod;
                }
            }
        }
        printf("%lld\n", cnt[n] % mod);
    }
    return 0;
}