//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int closetTarget(vector<string> &words, string target, int startIndex) {
        int ans = 1e8, n = words.size();
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == target){
                ans = min(ans, abs((startIndex - i + n) % n));
                ans = min(ans, abs((i - startIndex + n) % n));
            }
        }
        if (ans == 1e8) ans = -1;
        return ans;
    }
};