#include <bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff >> 1;
class dinic
{
public:
    int s, t;
    static const int maxn = 100010;
    static const int dmaxn = 10010;
    vector<int>f[dmaxn];
    bool vis[dmaxn];
    int cur[dmaxn],d[dmaxn];
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
} Di;
void fread(int &x)
{
    x = 0; char s = getchar();
    while (s < '0' || s > '9')
        s = getchar();
    while (s >= '0' && s <= '9') {
        x = x * 10 + s - '0';
        s = getchar();
    }
    return ;
}
int main()
{
    int n, m;
    fread(n); fread(m); fread(Di.s); fread(Di.t);
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        fread(a); fread(b); fread(c);
        Di.addedge(a, b, c);
    }
    printf("%d\n", Di.max_flow());
    return 0;
}