//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> evenOddBit(int n) {
        int cur = 0;
        vector<int>ans = {0, 0};
        while (n)
        {
            if (n & 1)
            {
                ans[cur & 1]++;
            }
            n >>= 1;
            cur++;
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