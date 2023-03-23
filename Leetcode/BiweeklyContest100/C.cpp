//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
        vector<bool>vis(nums.size(),false);
        for (int i = 0; i < nums.size(); ++i)
            q.push({nums[i],i});
        long long ans = 0;
        while (!q.empty())
        {
            auto x = q.top();
            q.pop();
            if (vis[x.second])
                continue;
            vis[x.second] = true;
            ans += x.first;
            if (x.second > 0)
                vis[x.second - 1] = true;
            if (x.second < nums.size() - 1)
                vis[x.second + 1] = true;
        }
        return ans;
    }
};

#ifdef LOCALLC
int main() {
    Solution sol;
    return 0;
}
#endif