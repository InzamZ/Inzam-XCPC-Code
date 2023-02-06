//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
  public:
    int cnt[100010];
    bool vis[1010][1010];
    bool isPossibleToCutPath(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        cout << m << " " << n << endl;
        queue<pair<int, int>>q;
        for (int i = 0; i < m + n - 2; ++i)
            cnt[i] = 0;
        q.push({m - 1, n - 1});
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            if (vis[x][y])
                continue;
            vis[x][y] = 1;
            cnt[x + y]++;
            if (x - 1 >= 0 && grid[x - 1][y] == 1) {
                q.push({x - 1, y});
            }
            if (y - 1 >= 0 && grid[x][y - 1] == 1) {
                q.push({x, y - 1});
            }
        }
        for (int i = 1; i < m + n - 2; ++i) {
            if (cnt[i] <= 1)
                return true;
        }
        return false;
    }
};
#ifdef LOCALLC
int main() {
    Solution sol;
    vector<vector<int>> grid = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    sol.isPossibleToCutPath(grid);
    return 0;
}
#endif