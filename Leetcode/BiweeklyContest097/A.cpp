//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> separateDigits(vector<int> &nums) {
        stack<int>q;
        vector<int>v;
        for (auto x : nums) {
            while (x) {
                q.push(x % 10);
                x /= 10;
            }
            while (!q.empty()) {
                v.push_back(q.top());
                q.pop();
            }
        }
        return v;
    }
};

int main() {
    Solution sol;
    return 0;
}