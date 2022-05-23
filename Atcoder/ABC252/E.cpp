//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define ff(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
const int inf = 1e18;
int T = 1, n, m, s, ans = 0, dis[maxn], pre[maxn], cnt[maxn];

struct edg {
    int id, v, w;
    edg() {}
    edg(int _id, int _v, int _w): id(_id), v(_v), w(_w) {}
};

struct inode {
    int dis, v;
    inode(int _dis, int _v): dis(_dis), v(_v) {}

    bool operator > (const inode &rhs) const {
        return dis > rhs.dis;
    }
};

priority_queue<inode, vector<inode>, greater<inode> > q;
vector<edg>e[maxn];

signed main() {
    FIO;
    cin >> n >> m ;
    f(i, 1, n) {
        dis[i] = inf;
        pre[i] = 0;
    }
    f(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back(edg(i, v, w));
        e[v].push_back(edg(i, u, w));
    }
    dis[1] = 0;
    q.push(inode(0, 1));
    while (!q.empty()) {
        inode tmp = q.top();
        q.pop();
        if (tmp.dis > dis[tmp.v])
            continue;
        ff(i, 0, e[tmp.v].size()) {
            edg tmp2 = e[tmp.v][i];
            if (tmp2.w + tmp.dis < dis[tmp2.v]) {
                dis[tmp2.v] = tmp2.w + tmp.dis;
                pre[tmp2.v] = tmp2.id;
                q.push(inode(dis[tmp2.v], tmp2.v));
            }
        }
    }
    f(i, 1, n) {
        if (pre[i])
            cout << pre[i] << " ";
    }
    return 0;
}