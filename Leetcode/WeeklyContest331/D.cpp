//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    map<long long, long long>mp1, mp2;
    long long minCost(vector<int> &basket1, vector<int> &basket2) {
        long long minx = 1e9;
        for (auto x : basket1) {
            mp1[x]++;
            minx = min(minx, 1ll * x);
        }
        for (auto x : basket2) {
            mp2[x]++;
            minx = min(minx, 1ll * x);
        }
        long long ans = 0, ok = 0;
        bool flag = 1;
        priority_queue<long long>q1;
        priority_queue<long long,vector<long long>, greater<long long>>q2;
        for (auto x : basket1) {
            if ((mp1[x] - mp2[x]) % 2 == 1) {
                flag = 0;
                break;
            }
            else if (mp1[x] - mp2[x] > 0) {
                mp1[x]--;
                mp2[x]++;
                q1.push(x);
            }
            else if (mp1[x] - mp2[x] < 0) {
                mp1[x]++;
                mp2[x]--;
                q2.push(x);
            }
        }
        for (auto x : basket2) {
            if ((mp1[x] - mp2[x]) % 2 == 1) {
                flag = 0;
                break;
            }
            else if (mp1[x] - mp2[x] > 0) {
                mp1[x]--;
                mp2[x]++;
                q1.push(x);
            }
            else if (mp1[x] - mp2[x] < 0) {
                mp1[x]++;
                mp2[x]--;
                q2.push(x);
            }
        }
        if (flag)
        {
            while(!q1.empty() && !q2.empty())
            {
                ans += min(minx * 2,min(q1.top(), q2.top()));
                q1.pop();
                q2.pop();
            }
        }
        if (flag && ok == 0)
            return ans;
        else
            return -1;
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