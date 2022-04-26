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
    int dp[200010][5][5];

    void update(int i, int j, int val, int t)
    {
        for (int k = 0; k < 3; ++k) {
            for (int l = 0; l < 3; ++l) {
                if (val < abs(i - k) + abs(j - l))
                    continue;
                dp[t][k][l] = max(dp[t][k][l], dp[t - 1][i][j]);
            }
        }
        return ;
    }

    static bool cmp1(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];
    }

    int getMaximumNumber(vector<vector<int>> &moles)
    {
        vector<int>v;
        map<int, int>mp;
        sort(moles.begin(), moles.end(), cmp1);
        for (int i = 0; i < moles.size(); ++i) {
            v.push_back(moles[i][0]);
            mp[moles[i][0]] = i;
        }
        for (int k = 0; k < v.size(); ++k) {
            if (k != 0)
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if (moles[k][0] < abs(i - 1) + abs(j - 1))
                            continue;
                        update(i, j, v[k] - v[k - 1], k);
                    }
                }
            dp[k][moles[k][1]][moles[k][2]]++;
        }
        int ans = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (v[v.size() - 1] < abs(i - 1) + abs(j - 1))
                    continue;
                ans = max(ans, dp[v.size() - 1][i][j]);
            }
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