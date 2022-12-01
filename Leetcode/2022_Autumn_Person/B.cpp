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
    int transportationHub(vector<vector<int>>& path) {
        vector<int>indeg(1010,0);
        vector<int>outdeg(1010,0);
        vector<bool>vis(1010,0);
        for (auto x: path)
        {
            indeg[x[1]]++; outdeg[x[0]]++;
            vis[x[1]] = vis[x[0]] = 1;
        }
        int ans = -1, n = 0;
        for (int i = 0; i <=1000; ++i)
        {
            if (vis[i]) n++;
        }

        for (int i = 0; i <=1000; ++i)
        {
            if (indeg[i] == n - 1 && outdeg[i] == 0)
                ans = i;
        }
        return ans;
    }
};