//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int cnt1[30], cnt2[30];
    bool isItPossible(string word1, string word2) {
        for (int i = 0; i < 30; ++i)
            cnt1[i] = cnt2[i] = 0;
        for (auto x : word1) {
            cnt1[x - 'a' + 1]++;
            if (cnt1[x - 'a' + 1]==1)
                cnt1[0]++;
        }
        for (auto x : word2) {
            cnt2[x - 'a' + 1]++;
            if (cnt2[x - 'a' + 1]==1)
                cnt2[0]++;
        }
        int del1 = 0, del2 = 0;
        int tmp1, tmp2;
        for (int i = 1; i <= 26; ++i) {
            for (int j = 1; j <= 26; ++j) {
                del1 = 0; del2 = 0;
                if (!cnt1[i] || !cnt2[j])
                    continue;
                tmp1 = cnt1[i];
                tmp2 = cnt2[j];
                if (!(--cnt1[i]))
                    del1--;
                if (cnt1[j] == 0)
                    del1++;
                if (!(--cnt2[j]))
                    del2--;
                if (cnt2[i] == 0)
                    del2++;
                if (cnt1[0] + del1 == cnt2[0] + del2)
                    return 1;
                cnt1[i] = tmp1;
                cnt2[j] = tmp2;
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;
    sol.isItPossible("aa", "bcd");
    return 0;
}