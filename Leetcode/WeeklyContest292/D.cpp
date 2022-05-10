#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    bool dp[105][105][205];
    int m, n;

    bool hasValidPath(vector<vector<char>> &grid)
    {
        n = grid.size(); m = grid[0].size();
        for (int i = 0; i <= 100; ++i)
            for (int j = 0; j <= 100; ++j)
                for (int k = 0; k <= 200; ++k)
                    dp[i][j][k] = false;
        dp[1][0][0] = dp[0][1][0] = true;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                if (grid[i - 1][j - 1] == '(')
                    for (int k = 1; k <= 200; ++k)
                        dp[i][j][k] = dp[i - 1][j][k - 1] | dp[i][j - 1][k - 1];
                else {
                    for (int k = 0; k <= 200; ++k)
                        dp[i][j][k] = dp[i - 1][j][k + 1] | dp[i][j - 1][k + 1];
                }
            }
        return dp[n][m][0];
    }
};