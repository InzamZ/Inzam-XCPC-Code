//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        auto check = [&] (long long x)
        {
            long long ans = 0;
            for (int i = 0; i < ranks.size(); ++i)
            {
                double tmp = x;
                tmp /= ranks[i];
                tmp = sqrt(tmp);
                ans += (long long) tmp;
            }
            return ans;
        };
        long long l = 1, r = 1e18;
        while (l < r)
        {
            long long mid = (l + r) >> 1;
            if (check(mid) >= cars)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

#ifdef LOCALLC
int main() {
    Solution sol;
    // [4,2,2,2]
    // [1,4,1,2]
    vector<int>v1 = {4, 2, 2, 2};
    vector<int>v2 = {1, 4, 1, 2};
    cout << sol.minCost(v1, v2) << endl;
    return 0;
}
#endif