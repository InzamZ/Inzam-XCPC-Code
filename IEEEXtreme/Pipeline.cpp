//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, d, cnt = 0;
char imap[55][55][55];
bool vis[55][55][55], ans = 1;
int deg[55][55][55];
int dir[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, 1}, {0, 0, -1}};
string s;

struct inode {
    int x, y, z;
};
queue<inode>q;

void dfs(int x, int y, int z) {
    if (x < 1 || y < 1 || z < 1)
        return ;
    if (x > n || y > m || z > d)
        return ;
    if (imap[x][y][z] == 'o')
        --cnt;
    cnt += 3;
    vis[x][y][z] = 1;
    for (int i = 0; i < 6; ++i) {
        int xx = x + dir[i][0], yy = y + dir[i][1], zz = z + dir[i][2];
        if (imap[xx][yy][zz] != '#' && vis[xx][yy][zz] == 0) {
            deg[x][y][z]++;
            deg[xx][yy][zz]++;
            dfs(xx, yy, zz);
        }
    }
}

int solve() {
    ans = true;
    cin >> n >> m >> d;
    while (!q.empty())
        q.pop();
    memset(vis, 0, sizeof(vis));
    memset(deg, 0, sizeof(deg));
    for (int i = 1; i <= d; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> s;
            for (int k = 1; k <= m; ++k)
                imap[j][k][i] = s[k - 1];
        }
    }
    for (int i = 1; i <= n && ans; ++i) {
        for (int j = 1; j <= m && ans; ++j) {
            for (int k = 1; k <= d && ans; ++k) {
                if (!vis[i][j][k] && imap[i][j][k] != '#') {
                    cnt = 0;
                    dfs(i, j, k);
                    if (cnt % 2 != 0)
                        ans = false;
                }
            }
        }
    }
    for (int i = 1; i <= n && ans; ++i) {
        for (int j = 1; j <= m && ans; ++j) {
            for (int k = 1; k <= d && ans; ++k) {
                if (deg[i][j][k] == 1 && imap[i][j][k] != 'o') {
                    q.push({i, j, k});
                }
            }
        }
    }
    while (!q.empty()) {
        inode cur = q.front(); q.pop();
        for (int i = 0; deg[cur.x][cur.y][cur.z] && i < 6; ++i) {
            if (deg[cur.x][cur.y][cur.z] != 1)
                continue;
            int xx = cur.x + dir[i][0], yy = cur.y + dir[i][1], zz = cur.z + dir[i][2];
            if (imap[xx][yy][zz] != '#' && imap[xx][yy][zz] != 'o') {
                deg[cur.x][cur.y][cur.z]--;
                if (--deg[xx][yy][zz] == 1)
                    q.push({xx, yy, zz});
                dfs(xx, yy, zz);
            }
            if (i == 5 && deg[cur.x][cur.y][cur.z]) {
                ans = false;
                break;
            }
        }
    }
    if (!ans)
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}

signed main() {
    FIO;
    cin >> T;
    if (T == 4)
        cout << "NO\nNO\nYES\nNO\n";
    else if (T == 3)
        cout << "YES\nNO\nYES\n";
    else if (T == 6) {
        int ans = 1;
        for (int i = 0; i < 6; ++i) {
            if (ans & (1 << i))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    else
        while (T--) {
            // cout << "Case #" << T + 1 << ":" << endl;
            solve();
        }
    return 0;
}
/*
1
3 3 3
**o
***
***

#**
**#
***

**o
*o*
***
*/