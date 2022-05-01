//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, ans = 0;
class Solution
{
public:
    int countDistinct(vector<int> &nums, int k, int p)
    {
        int ans = 0;
        map<vector<int>, int>mp;
        for (int i = 0; i < nums.size(); ++i) {
            vector<int>a;
            int cnt = 0;
            for (int j = i; j < nums.size(); ++j) {
                a.push_back(nums[j]);
                if (nums[j] % p == 0)
                    cnt++;
                if (cnt <= k && mp[a] == 0) {
                    ans++;
                    mp[a] = 1;
                }
            }
        }
        return ans;
    }
};
int main()
{
    vector<int>a = {1, 9, 8, 7, 19};
    int k = 1, p = 6;
    auto soloution = Solution();
    soloution.countDistinct(a, k, p);
    return 0;
}