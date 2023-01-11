//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    priority_queue<int> pq;
    long long maxKelements(vector<int> &nums, int k) {
        while(!pq.empty()) pq.pop();
        for (auto x : nums)
            pq.push(x);
        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            int res = pq.top();
            ans += res;
            pq.pop();
            pq.push(ceil(res / 3.0));
        }
        return ans;
    }
};

int main() {
    Solution sol;
    return 0;
}