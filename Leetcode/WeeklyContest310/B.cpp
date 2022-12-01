//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int partitionString(string s) {
        int n = s.length(), ans = 1;
        vector<int>cnt(30, 0);
        for (int i = 0; i < n; ++i) {
            if (!cnt[s[i] - 'a'])
                ++cnt[s[i] - 'a'];
            else {
                for (int i = 0; i < 30; ++i)
                    cnt[i] = 0;
                ++cnt[s[i] - 'a'];
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution ss;
    string s = "abacaba";
    cout << ss.partitionString(s);
    return 0;
}