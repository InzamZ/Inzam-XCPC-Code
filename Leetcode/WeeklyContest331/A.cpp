//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long pickGifts(vector<int> &gifts, int k) {
        priority_queue<int>q;
        long long ans = 0;
        for (auto x : gifts) {
            q.push(x);
            ans += x;
        }
        for (int i = 1; i <= k; ++i) {
            int cnt = q.top();
            cnt = cnt - floor(sqrt(cnt));
            ans -= cnt;
            cnt = q.top() - cnt;
            q.pop();
            cout << cnt << endl;
            q.push(cnt);
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