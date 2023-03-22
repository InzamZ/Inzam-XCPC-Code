//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int cnt[1010], ans = 0;
    void dfs (int rt, vector<int> &nums, int k, int dep) {
        cnt[nums[rt]]++;
        ans++;
        int siz = nums.size();
        for (int i = rt + 1; i < siz; i++) {
            if (nums[i] <= k || (nums[i] - k > 0 && cnt[nums[i] - k] == 0))
                dfs(i, nums, k,dep + 1);
        }
        cnt[nums[rt]]--;
    }
    int beautifulSubsets(vector<int> &nums, int k) {
        int siz = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < siz; i++) {
            dfs(i, nums, k, 0);
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