//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long cnt[100005], cnttmp[100005];
    long long maxPower(vector<int> &stations, int r, int k) {
        long long ll = 0, rr = 1e18;
        long long siz = stations.size();
        for (int i = 0; i <= siz; ++i)
            cnttmp[i] = cnt[i] = 0;
        for (long long i = 0; i < stations.size(); ++i) {
            cnt[max(0ll, i + 1 - r)] += stations[i];
            cnt[min(siz + 1, i + r + 2)] -= stations[i];
        }
        long long kk;
        long long mid = (ll + rr) / 2,cur = 0;
        bool check;
        for (int i = 0; i <= siz; ++i) {
            cnttmp[i] = cnt[i];
        }
        while (ll + 1 < rr) {
            mid = (ll + rr) / 2;
            check = 1;
            kk = k;
            for (int i = 0; i <= siz; ++i) {
                cnt[i] = cnttmp[i];
            }
            cur = cnt[0];
            for (long long i = 1; i <= siz; ++i) {
                cur += cnt[i];
                if (cur < mid) {
                    kk -= mid - cur;
                    cnt[min(i + 1 + 2 * r, siz + 1)] -= mid - cur;
                    cur = mid;
                }
                if (kk < 0) {
                    check = 0;
                    break;
                }
            }
            if (check)
                ll = mid;
            else
                rr = mid;
        }
        return ll;
    }
};


int main() {
    Solution sol;
    vector<int>stations = {1, 2, 4, 5, 0};
    int r = 1;
    int k = 2;
    cout << sol.maxPower(stations, r, k);
    return 0;
}