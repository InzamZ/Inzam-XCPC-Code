//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 10;
stack<int>q;
int node_cnt = 0, n, m, inst[maxn], beg[maxn];
int dfn[maxn], low[maxn], Index = 0;
int belong[maxn], bcnt = 0, ly[maxn], gxw[maxn], val[maxn];
vector<int>e[maxn];
void tarjan(int rt) {
    low[rt] = dfn[rt] = ++Index;
    q.push(rt);
    inst[rt] = true;
    for (auto v : e[rt]) {
        if (!dfn[v]) {
            tarjan(v);
            low[rt] = min(low[rt], low[v]);
        }
        else if (inst[v])
            low[rt] = min(low[rt], dfn[v]);
    }
    if (dfn[rt] == low[rt]) {
        int j;
        bcnt++;
        do {
            j = q.top();
            q.pop();
            inst[j] = false;
            gxw[bcnt] += val[j];
            belong[j] = bcnt;
        }
        while (j != rt);
    }
}
signed main() {
    int ans = 0;
    scanf ("%lld %lld", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf ("%lld %lld", &u, &v);
        e[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i])
            tarjan(i);
    }
    node_cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (low[i] == dfn[1]) {
            ++ans;
            printf("%lld\n", i);
        }
    }
    printf("%lld\n", ans);
    return 0;
}