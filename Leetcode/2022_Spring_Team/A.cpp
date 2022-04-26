//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("/out.txt" , "w", stdout);
const int maxn = 1e5 + 10;
int T = 1, n, ans = 0;

class Solution
{
public:
    int getMinimumTime(vector<int> &time, vector<vector<int>> &fruits, int limit)
    {
        int n = fruits.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            int t = fruits[i][1] / limit;
            if (fruits[i][1] % limit)
                ++t;
            t *= time[fruits[i][0]];
            ans += t;
        }
        return ans;
    }
};

int main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n;
        cout << ans << '\n';
    }
    return 0;
}