//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximizeGreatness(vector<int> &nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); i++)
            pq.push(nums[i]);
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size() && !pq.empty(); i++) {
            while (!pq.empty() && nums[i] >= pq.top()) {
                pq.pop();
            }
            if (pq.empty())
                break;
            ans++; pq.pop();
        }
        return ans;
    }
};

#ifdef LOCALLC

int main() {
    Solution sol;
    vector<string> words ({"aba", "bcb", "ece", "aa", "e"});
    vector<vector<int>> queries ({{0, 2}, {1, 4}, {1, 1}});
    sol.vowelStrings(words, queries);
    return 0;
}

#endif