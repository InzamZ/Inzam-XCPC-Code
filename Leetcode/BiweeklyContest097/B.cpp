//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int vis[10010];
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans = 0;
        for (int i = 0; i <= n; ++i) vis[i] = 0;
        for (auto x: banned) vis[x] = 1;
        for (int i = 1; i <= n && maxSum >= i; ++i)
        {
            if (vis[i]) continue;
            ++ans;
            maxSum -= i;
        }
        return ans;
    }
};