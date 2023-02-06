//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCapability(vector<int> &nums, int k) {
        int n = nums.size();
        auto check = [ = ] (int x) {
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] <= x) {
                    cnt++;
                    ++i;
                }
            }
            cout << x << " " << cnt << endl;
            return cnt < k;
        };
        int l = 0, r = 1e9 + 1;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (check(mid))
                l = mid;
            else
                r = mid;
        }
        return r;
    }
};

#ifdef LOCALLC
int main() {
    Solution sol;
    return 0;
}
#endif