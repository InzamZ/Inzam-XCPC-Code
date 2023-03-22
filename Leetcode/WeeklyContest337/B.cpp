//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        vector<pair<int,int> > v(grid.size() * grid.size());
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
            {
                v[grid[i][j]] = {i, j};
            }
        }
        if (v[0] != make_pair(0, 0)) return false;
        for (int i = 1; i < grid.size() * grid.size(); i++)
        {
            int x = abs(v[i].first - v[i - 1].first);
            int y = abs(v[i].second - v[i - 1].second);
            if (x > y) swap(x, y);
            if (x != 1 || y != 2) return false;
        }
        return true;
    }
};

#ifdef LOCALLC

int main() {
    Solution sol;
    vector<string> words ({"aba", "bcb", "ece", "aa", "e"});
    vector<vector<int>> queries ({{0, 2}, {1, 4}, {1, 1}});
    sol.vowelStrings(words, queries);
    return 0;
}

#endif