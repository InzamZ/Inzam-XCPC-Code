#include <bits/stdc++.h>
using namespace std;
#define int long long
class dinic
{
public:
    int s, t, n, m;
    static const int maxn = 100010;
    static const int dmaxn = 10010;
    // static const int INF = 0x7fffffff;
    static const int inf = 0x7fffffffffffffff;
    vector<int>f[dmaxn];
    bool vis[dmaxn];
    int cur[dmaxn], d[dmaxn];
    struct edge {
        int to, cap, flow;
    };
    vector<edge>e;
    /**
     * @brief 读入图的边
     * @param from 边的起点
     * @param to 边的终点
     * @param cap 边的最大流量
     */
    void addedge(int from, int to, int cap)
    {
        int m = e.size();
        e.push_back((edge) {
            to, cap, 0
        });
        f[from].push_back(m);
        e.push_back((edge) {
            from, 0, 0
        });
        f[to].push_back(m + 1);
    }
    bool bfs()
    {
        queue<int>q;
        q.push(s);
        memset(vis, 0, sizeof(vis));
        d[s] = 0;
        vis[s] = 1;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            int len = f[x].size();
            for (int i = 0; i < len; i++) {
                edge &o = e[f[x][i]];
                if (!vis[o.to] && o.cap > o.flow) {
                    d[o.to] = d[x] + 1;
                    vis[o.to] = 1;
                    q.push(o.to);
                }
            }
        }
        return vis[t];
    }
    /**
     * @brief dfs寻找增广路，可以多次寻找
     *
     * @param x 当前所在的节点
     * @param a 当前的流量
     * @return 本次增广路得到的流量
     */
    int dfs(int x, int a)
    {
        if (x == t || a == 0)
            return a;
        int flow = 0; int r, len = f[x].size();
        for (int &i = cur[x]; i < len; i++) {
            edge &o = e[f[x][i]];
            if (d[x] + 1 == d[o.to] && (r = dfs(o.to, min(a, o.cap - o.flow))) > 0) {
                o.flow += r;
                e[f[x][i] ^ 1].flow -= r;
                flow += r;
                a -= r;
                if (a == 0)
                    break;
            }
        }
        return flow;
    }
    /**
     * @brief 求最大流，要求事先完成读入
     */
    int max_flow()
    {
        int flow = 0;
        while (bfs()) {
            memset(cur, 0, sizeof(cur));
            flow += dfs(s, inf);
        }
        return flow;
    }
}DI;
/**
 * @param m 边数
 * @param n 点数
 * @param E 边的总集合
 * @param e 连接每个节点的边的集合
 * @param a 每次增广路过程中到达每个节点的最大流量
 * @param p 每次增广路节每个点选择增广的边
 */
class EK
{
public:
    struct edgeNode {
        int from, to, cap, flow;
        edgeNode(int _from, int _to, int _cap, int _flow): from(_from), to(_to), cap(_cap), flow(_flow) {}
    };
    int m, n, s, t;
    static const int maxn = 100010;
    // static const int INF = 0x7fffffff;
    static const int INF = 0x7fffffffffffffff;
    vector<edgeNode>E;
    vector<int>e[maxn];
    int a[maxn], p[maxn];
    void addedge(int from, int to, int cap)
    {
        E.push_back(edgeNode{from, to, cap, 0});
        E.push_back(edgeNode{to, from, 0, 0});
        e[from].push_back(E.size() - 2);
        e[to].push_back(E.size() - 1);
    }
    int max_flow()
    {
        int flow = 0;
        while (1) {
            queue<int>q;
            q.push(s);
            for (int i = 0; i <= n; ++i)
                a[i] = 0;
            a[s] = INF;
            while (!q.empty()) {
                int rt = q.front(); q.pop();
                for (int i = 0; i < e[rt].size(); ++i) {
                    auto o = E[e[rt][i]];
                    if (!a[o.to] && o.cap > o.flow) {
                        a[o.to] = min(a[rt], o.cap - o.flow);
                        p[o.to] = e[rt][i];
                        q.push(o.to);
                    }
                }
                if (a[t])
                    break;
            }
            if (!a[t])
                break;
            for (int i = t; i != s; i = E[p[i]].from) {
                E[p[i]].flow += a[t];
                E[p[i] ^ 1].flow -= a[t];
            }
            flow += a[t];
        }
        return flow;
    }
};
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> DI.n >> DI.m >> DI.s >> DI.t;
    for (int i = 1; i <= DI.m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        DI.addedge(a, b, c);
    }
    printf("%lld\n", DI.max_flow());
    return 0;
}