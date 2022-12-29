//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int ans = n;
        int cnt[3], l = 0, r = n - 1;
        cnt[0] = cnt[1] = cnt[2] = 0;
        if (k == 0) return 0;
        for (int i = 0; i < n; ++i) {
            cnt[s[i] - 'a']++;
            if (getmin(cnt) == k) {
                l = i;
                ans = i + 1;
                break;
            }
        }
        if (l == 0) return -1;
        for (r = n - 1; r >= 0; --r) {
            if (getmin(cnt) >= k) ans = min(ans,l + 1 + n - r);
            ++cnt[s[r]-'a'];
            while(l > 0 && getmin(cnt) >= k)
            {
                --cnt[s[l]-'a'];
                --l;
                if (getmin(cnt) >= k) ans = min(ans,l + 1 + n - r);
            }
        }
        return ans;
    }
    inline int getmin(int *cnt) {
        return min(cnt[0], min(cnt[1], cnt[2]));
    }
};