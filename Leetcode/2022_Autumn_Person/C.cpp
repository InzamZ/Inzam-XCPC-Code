//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("/out.txt" , "w", stdout);
const int maxn = 1e5 + 10;
int T = 1, n, ans = 0;

class Solution {
  public:
#define pii pair<int,int>
#define getc(x) plate[x.first][x.second]
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<int>> ballGame(int num, vector<string> &plate) {
        vector<vector<int>>ans;
        vector<vector<int>>vis(1005, vector<int>(1005, 0));
        int n = plate.size(), m = plate[0].size();
        queue<pii> q;
        queue<pii> qdir;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (plate[i][j] == 'O') {
                    if (min(min(i, n - 1 - i), min(j, m - 1 - j)) > num)
                        continue;
                    for (int k = 0; k <= 3; ++k) {
                        pii u;
                        u.first = i - dir[k][0];
                        u.second = j - dir[k][1];
                        if (u.first < 0 || u.first >= n)
                            continue;
                        if (u.second < 0 || u.second >= m)
                            continue;
                        q.push(u);
                        if (getc(u) == 'E')
                            qdir.push({(k + 3) % 4, 1});
                        else if (getc(u) == 'W')
                            qdir.push({(k + 1) % 4, 1});
                        else
                            qdir.push({k, 1});
                    }
                }
            }
        }
        while (!q.empty()) {
            pii cur = q.front();
            q.pop();
            if (getc(cur) != 'O') {
                pii u;
                int i = qdir.front().first;
                int j = qdir.front().second;
                qdir.pop();
                u.first = cur.first - dir[i][0];
                u.second = cur.second - dir[i][1];
                if (vis[cur.first][cur.second] & (1 << i)) continue;
                if (j + min(min(cur.first, n - 1 - cur.first), min(cur.second, m - 1 - cur.second)) > num)
                    continue;
                vis[cur.first][cur.second] |= (1 << i);
                if (u.first < 0 || u.first >= n)
                    continue;
                if (u.second < 0 || u.second >= m)
                    continue;
                if (j == num)
                    continue;
                if (getc(u) == 'E') {
                    if (!(vis[u.first][u.second] & (1 << (i + 3) % 4))) {
                        qdir.push({(i + 3) % 4, j + 1});
                        q.push(u);
                    }
                }
                else if (getc(u) == 'W') {
                    if (!(vis[u.first][u.second] & (1 << (i + 1) % 4))) {
                        qdir.push({(i + 1) % 4, j + 1});
                        q.push(u);
                    }
                }
                else {
                    if (!(vis[u.first][u.second] & (1 << i))) {
                        qdir.push({i, j + 1});
                        q.push(u);
                    }
                }
            }
            else
                qdir.pop();
        }
        for (int i = 1; i < n - 1; ++i) {
            if (plate[i][0] == '.' && (vis[i][0] & 1))
                ans.push_back({i, 0});
            if (plate[i][m - 1] == '.' && (vis[i][m - 1] & (1 << 2)))
                ans.push_back({i, m - 1});
        }
        for (int i = 1; i < m - 1; ++i) {
            if (plate[0][i] == '.' && (vis[0][i] & (1 << 1)))
                ans.push_back({0, i});
            if (plate[n - 1][i] == '.' && (vis[n - 1][i] & (1 << 3)))
                ans.push_back({n - 1, i});
        }
        return ans;
    }
};


int main() {
    int num = 3;
    vector<string> plate = {".....", "....O", "....O", "....."};
    auto sol = new Solution;
    sol->ballGame(num, plate);
    return 0;
}