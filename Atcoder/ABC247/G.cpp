#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node {
    int v, cap, cost, back;
} o[100010];
int cnt = 1;
vector<int>e[100000];
int mcost = 0, mflow = 0, INF = 1e9;
int inq[100000], pre[100000], xb[100000], dis[100000], flow[100000];
queue<int>q;
void addnode(int from, int to, int val, int w)
{
    o[cnt].v = to;
    o[cnt].cap = val;
    o[cnt].cost = w;
    o[cnt].back = cnt + 1;
    e[from].push_back(cnt);
    ++cnt;
    o[cnt].v = from;
    o[cnt].cap = 0;
    o[cnt].cost = -w;
    o[cnt].back = cnt - 1;
    e[to].push_back(cnt);
    ++cnt;
}

int spfa(int s, int t)
{
    memset(dis, 127, sizeof(dis));
    memset(inq, 0, sizeof(inq));
    memset(pre, -1, sizeof(pre));
    while (!q.empty())
        q.pop();
    int inf = dis[0];
    inq[s] = 1;
    q.push(s);
    dis[s] = 0;
    pre[s] = 0;
    flow[s] = 0x7fffffff;
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        inq[tmp] = 0;
        int len = e[tmp].size();
        for (int i = 0; i < len; i++) {
            int rea = e[tmp][i];
            if (o[rea].cap > 0 && dis[o[rea].v] > dis[tmp] + o[rea].cost) {
                dis[o[rea].v] = dis[tmp] + o[rea].cost;
                pre[o[rea].v] = tmp;
                xb[o[rea].v] = rea;
                flow[o[rea].v] = min(flow[tmp], o[rea].cap);
                if (!inq[o[rea].v]) {
                    inq[o[rea].v] = 1;
                    q.push(o[rea].v);
                }
            }
        }
    }
    if (dis[t] >= inf)
        return 0;
    return 1;
}

void max_flow(int s, int t)
{
    while (spfa(s, t)) {
        int k = t;
        while (k != s) {
            o[xb[k]].cap -= flow[t];
            o[o[xb[k]].back].cap += flow[t];
            k = pre[k];
        }
        mflow += flow[t];
        mcost += flow[t] * dis[t];
    }
}
bool ia[160], ib[160];
signed main()
{
    int n, m, s, t;
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i) {
        int a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        addnode(a, b + 150, 1, -c);
        if (!ia[a]) addnode(0, a, 1, 0), ia[a] = 1;
        if (!ib[b]) addnode(b + 150, 301, 1, 0), ib[b] = 1;
    }
    int k = 1;
    addnode(301, 302, 1, 0);
    max_flow(0, 302);
    vector<int>ans;
    while (mflow == k) {
        ans.push_back(-mcost);
        addnode(301, 302, 1, 0);
        max_flow(0, 302);
        ++k;
    }
    printf("%ld\n", ans.size());
    for (auto x : ans) printf("%lld\n", x);
    return 0;
}