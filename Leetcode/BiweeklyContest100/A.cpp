//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int distMoney(int money, int children) {
        int ans = 0;
        money -= children;
        ans = money / 7;
        if (ans == children - 1 && money % 7 == 3)
            --ans;
        if (7 * children == money)
            return children;
        else if (ans >= children)
            ans = min(ans, children - 1);
        if (money < 0)
            ans = -1;
        return ans;
    }
};

#ifdef LOCALLC
int main() {
    Solution sol;
    return 0;
}
#endif