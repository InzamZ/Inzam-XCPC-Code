//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define endl '\n'
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("/out.txt" , "w", stdout);
const int maxn = 1e5 + 10;
int T = 1, n, ans = 0;

class Solution {
  public:
    int dp[5010];
    int calcost(string &str, int pick) {
        int l = 0, r = str.length() - 1, res = 0;
        int lcos = 0, rcos = 0;
        while ( l <= r) {
            if ((1 << l) & pick == 0)
                lcos++, l++;
            else if ((1 << r) & pick == 0)
                rcos++, r--;
            else if (l == r) {
                res += lcos * rcos;
                break;
            }
            else {
                if (lcos * (rcos + r - l) > rcos * (lcos + r - l)) {
                    r--;
                    res += rcos * (lcos + r - l);
                }
                else {
                    l++;
                    res += lcos * (rcos + r - l);
                }
            }
        }
        return res;
    }
    int Leetcode(vector<string> &words) {
        int ans = 4;
        map<int, int>mp;
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        // mp['e'] = 4; mp['l'] = 3; mp['o'] = 2;mp['t'] =mp['h'] = mp['c'] = mp['d'] = 1;
        for (int i = 0; i < words.size(); ++i) {
            dp[0] = 0;
            for (int j = 0; j < (1 << words[i].size()); ++j) {
                int cnt[8], fg = 1;
                for (int k = 0; k < 8; ++k)
                    cnt[k] = 0;
                for (int k = 0; fg && k < words[i].size(); ++k) {
                    if (((1ll << k) & j ) == 0) {
                        continue;
                    }
                    if (words[i][k] == 'e')
                        cnt[0]++;
                    else if (words[i][k] == 'l')
                        cnt[1]++;
                    else if (words[i][k] == 'o')
                        cnt[2]++;
                    else if (words[i][k] == 't')
                        cnt[3]++;
                    else if (words[i][k] == 'h')
                        cnt[4]++;
                    else if (words[i][k] == 'c')
                        cnt[5]++;
                    else if (words[i][k] == 'd')
                        cnt[6]++;
                    else
                        fg = 0;
                }
                if (fg == 0)
                    continue;
                int cnttmp[8];
                for (int k = 0; k < 8; ++k)
                    cnttmp[k] = cnt[k];
                for (int k = 0; k < ( 1 << 11); ++k) {
                    int tmp = k;
                    for (int l = 0; l < 8; ++l)
                        cnt[l] = cnttmp[l];
                    cnt[6] += (tmp & 1); tmp >>= 1;
                    cnt[5] += (tmp & 1); tmp >>= 1;
                    cnt[4] += (tmp & 1); tmp >>= 1;
                    cnt[3] += (tmp & 1); tmp >>= 1;
                    cnt[2] += (tmp & 3); tmp >>= 2;
                    cnt[1] += (tmp & 3); tmp >>= 2;
                    cnt[0] += tmp; tmp >>= 2;
                    if (dp[k] == 0x3f3f3f3f || cnt[0] > 4 || cnt[1] > 3 || cnt[2] > 2 || cnt[3] > 1 || cnt[4] > 1 || cnt[5] > 1 || cnt[6] > 1)
                        continue;
                    int _ = ((((((cnt[0] << 2) | cnt[1]) << 2 | cnt[2]) << 1 | cnt[3]) << 1 | cnt[4]) << 1 | cnt[5]) << 1 | cnt[6];
                    int cost = calcost(words[i], j);
                    dp[_] = min(dp[_], dp[k] + cost);
                }
            }
        }
        ans = 1263;
        return dp[ans];
    }

};

int main() {
    vector<string>v = {"hold", "engineer", "cost", "level"};
    Solution T;
    cout << T.Leetcode(v) << endl;
}