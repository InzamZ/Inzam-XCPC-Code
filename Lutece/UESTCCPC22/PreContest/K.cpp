#include<cstdio>
#include<queue>
#include<stack>
#include<iostream>
#include<vector>
using namespace std;
struct _Edge {
    int v; int w;
};
bool visited[200005], cir[200005];
vector<_Edge> Edge[200005];
int pre[200005], deg[200005];
int pos[200005];
stack<int>path;
bool ans = 0;
inline void dfs(int node, int last)
{
    if (!cir[node])
        return ;
    path.push(node);
    pos[node] = path.size();
    visited[node] = 1;
    for (int i = 0; i < Edge[node].size(); i++) {
        if (Edge[node][i].v == last)
            continue;
        if (ans)
            return ;
        if (visited[Edge[node][i].v]) {
            if (pre[pos[node]]^pre[pos[Edge[node][i].v]]^Edge[node][i].w) {
                ans = 1;
                return ;
            }
            // cout<<Edge[node][i].v<<' '<<path.top()<<endl;
            // path.pop();
            // return ;
        }
        else {
            pre[pos[node] + 1] = pre[pos[node]] ^ Edge[node][i].w;
            if (cir[Edge[node][i].v])
                dfs(Edge[node][i].v, node);
        }
    }
    visited[node] = 0;
    path.pop();
}

inline char nc()
{
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}
inline long long _read()
{
    char ch = nc(); long long sum = 0;
    while (!(ch >= '0' && ch <= '9'))
        ch = nc();
    while (ch >= '0' && ch <= '9')
        sum = sum * 10 + ch - 48, ch = nc();
    return sum;
}

int main()
{
    int T;
    T = _read();
    while (T--) {
        int n, m, cnt = 0;
        ans = 0;
        pre[0] = 0;
        n = _read();
        m = _read();
        for (int i = 1; i <= n; i++) {
            visited[i] = 0;
            pre[i] = 0;
            Edge[i].clear();
        }
        for (int i = 0; i < m; i++) {
            int u, v, w;
            u = _read();
            v = _read();
            w = _read();
            _Edge tmp;
            tmp.v = v;
            tmp.w = w;
            Edge[u].push_back(tmp);
            tmp.v = u;
            Edge[v].push_back(tmp);
            deg[u]++;
            deg[v]++;
        }
        queue<int>q;
        for (int i = 1; i <= n; i++) {
            // cout<<deg[i]<<endl;
            if (deg[i] == 1) {
                q.push(i);
                cir[i] = 0;
            }
        }
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            // cout<<now<<' ';
            for (int i = 0; i < Edge[now].size(); i++) {
                int nxt = Edge[now][i].v;
                deg[nxt]--;
                if (deg[nxt] == 1) {
                    q.push(nxt);
                    cir[i] = 0;
                }
            }
        }
        if (n == 2) {
            printf("Yes\n");
            continue;
        }
        pos[0] = 0;
        dfs(1, 0);
        if (ans)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}