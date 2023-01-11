//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumCount(vector<int> &nums) {
        int ans = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int pos = nums.end() - lower_bound(nums.begin(), nums.end(), 1);
        return max(ans, pos);
    }
};

int main() {
    Solution sol;
    return 0;
}