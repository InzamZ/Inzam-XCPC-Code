//InzamZ
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
class Solution {
  public:
    long long countSubarrays(vector<int> &nums, long long k) {
        long long sum = 0, ans = 0 ;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (r >= l && sum * (r - l + 1) >= k) {
                sum -= nums[l];
                l++;
            }
            ans += r - l + 1;
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