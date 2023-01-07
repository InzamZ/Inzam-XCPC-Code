//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int xorBeauty(vector<int> &nums) {
        int ans = 0;
        for (auto v : nums)
            ans ^= v;
        return ans;
    }
};


int main() {
    Solution sol;
    return 0;
}