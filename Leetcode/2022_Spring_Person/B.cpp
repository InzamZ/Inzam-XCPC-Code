//InzamZ
//
#include <iostream>
#include <algorithm>
#include <vector>

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
    int perfectMenu(vector<int>& materials, vector<vector<int>>& cookbooks,vector<vector<int>>& attribute, int limit) {
        int ans = -1;
        for (int i = 0; i < (1 << cookbooks.size()); ++i)
        {
            bool ok = 1;
            int full = 0, res = 0;
            vector<int> m(materials);
            for (int j = 0; ok && j < cookbooks.size(); ++j)
            {
                if (i & (1 << j)) {
                    for (int k = 0; ok && k < materials.size(); ++k)
                    {
                        m[k] -= cookbooks[j][k];
                        if (m[k] < 0) ok = 0; 
                    }
                    if (ok) 
                    {
                        res += attribute[j][0];
                        full += attribute[j][1];
                    }
                }
            }
            if (ok && full >= limit) ans = max(ans, res);
        }
        return ans;
    }
};