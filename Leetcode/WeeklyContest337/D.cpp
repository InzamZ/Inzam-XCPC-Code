//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findSmallestInteger(vector<int> &nums, int value) {
        vector<int>cnt(value);
        for (int i = 0; i < nums.size(); i++)
            cnt[(nums[i] % value + value) % value]++;
        int ans = cnt[0];
        for (auto x : cnt)
            ans = min(ans, x);
        for (int i = 0; i < value; i++) {
            if (cnt[i] == ans)
                return ans * value + i;
        }
        return ans * value;
    }
};

#ifdef LOCALLC
int main() {
    Solution sol;
    // [4,2,2,2]
    // [1,4,1,2]
    vector<int>v1 = {4, 2, 2, 2};
    vector<int>v2 = {1, 4, 1, 2};
    cout << sol.minCost(v1, v2) << endl;
    return 0;
}
#endif