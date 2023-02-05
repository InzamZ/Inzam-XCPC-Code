//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int cnt[100010];
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries) {
        char ch[5] = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < words.size(); ++i ) {
            int len = words[i].size();
            int flag1 = 0, flag2 = 0;
            for (int k = 0; k < 5; ++k) {
                if (words[i][0] == ch[k])
                    flag1 = 1;
                if (words[i][len - 1] == ch[k])
                    flag2 = 1;
            }
            if (flag1 && flag2)
                cnt[i]++;
            if (i)
                cnt[i] += cnt[i - 1];
            cout << cnt[i] << endl;
        }
        vector<int>ans;
        for (auto x : queries) {
            int l = x[0], r = x[1];
            if (l == 0)
                ans.push_back(cnt[r]);
            else
                ans.push_back(cnt[r] - cnt[l - 1]);
            // if (l) cout << cnt[r] << " " << cnt[l - 1] << endl;
            // else cout << cnt[r] << endl;
        }
        return ans;
    }
};

#ifdef LOCALLC

int main() {
    Solution sol;
    vector<string> words ({"aba","bcb","ece","aa","e"});
    vector<vector<int>> queries ({{0, 2}, {1, 4}, {1, 1}});
    sol.vowelStrings(words, queries);
    return 0;
}

#endif