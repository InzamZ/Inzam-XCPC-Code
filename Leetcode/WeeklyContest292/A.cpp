//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestGoodInteger(string num)
    {
        int ans = -1;
        for (int i = 2; i < num.size(); i++) {
            if (num[i] == num[i - 1] && num[i - 1] == num[i - 2])
                ans = max(ans, num[i] - '0');
        }
        if (ans == -1)
            return "";
        else
            return to_string(ans) + to_string(ans) + to_string(ans);
    }
};
