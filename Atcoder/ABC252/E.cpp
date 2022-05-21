#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define int long long
#define inf (1000000000000000ll)
const int maxn = 500010;

struct bian {
    int u, v, cnt, id;
    long long w;
} e[maxn];

int first[maxn], inext[maxn];
long long dis[maxn];
bool d[maxn], flag[maxn];

vector<int>st;

void dfs(int u, int cost) {
    d[u] = true;
    for (auto x : st)
        flag[e[x].id] = 1;
    for (int i = first[u]; i != -1; i = inext[i]) {
        int v = e[i].v;
        if (!d[v] && cost + e[i].w == dis[v]) {
            st.push_back(i);
            dfs(v, cost + e[i].w);
            st.pop_back();
        }
    }
}

signed main() {
    int n, m, s;
    memset(first, -1, sizeof(first));
    scanf ("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        if (i == 1)
            dis[i] = 0;
        else
            dis[i] = inf;
        d[i] = true;
    }
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        scanf ("%lld%lld%lld", &e[i * 2].u, &e[i * 2].v, &e[i * 2].w);
        e[i * 2].id = i;
        a = e[i * 2].u;
        b = e[i * 2].v;
        c = e[i * 2].w;
        inext[2 * i] = first[a];
        first[a] = 2 * i;
        e[i * 2 - 1].u = b;
        e[i * 2 - 1].v = a;
        e[i * 2 - 1].w = c;
        e[i * 2 - 1].id = i;
        inext[2 * i - 1] = first[b];
        first[b] = 2 * i - 1;
    }
    int t = n, f;
    while (t--) {
        int minn = inf;
        for (int i = 1; i <= n; i++) {
            if (dis[i] <= minn && d[i]) {
                f = i;
                minn = dis[i];
            }
        }
        d[f] = !d[f];
        for (int i = first[f]; i != -1; i = inext[i]) {
            if (dis[e[i].v] > dis[f] + e[i].w)
                dis[e[i].v] = dis[f] + e[i].w;
        }
    }
    for (int i = 1; i <= n; i++)
        d[i] = 0;
    dfs(1, 0);
    for (int i = 1; i <= m; i++)
        if (flag[i])
            printf ("%lld ", i);
    return 0;
}