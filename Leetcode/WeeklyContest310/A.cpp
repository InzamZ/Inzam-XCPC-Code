//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int mostFrequentEven(vector<int> &nums) {
        int n = nums.size(), ans = -1, ansc = 0;
        vector<int>cnt(100005, 0);
        for (int i = 0; i < n; ++i) {
            cnt[nums[i]]++;
            if (cnt[nums[i]] >= ansc && nums[i] % 2 == 0) {
                if (ansc == cnt[nums[i]])
                    ans = min(ans, nums[i]);
                else {
                    ans = nums[i];
                    ansc = cnt[nums[i]];
                }
            }
        }
        return ans;
    }
};