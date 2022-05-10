#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    long long d[100010][2];

    int countTexts(string pressedKeys)
    {
        const long long mod = 1e9 + 7;
        d[0][0] = d[0][1] = 1;
        for (int i = 1; i <= 100000; i++) {
            d[i][0] += d[i - 1][0];
            d[i][1] += d[i - 1][1];
            if (i >= 2) {
                d[i][0] += d[i - 2][0];
                d[i][1] += d[i - 2][1];
            }
            if (i >= 3) {
                d[i][0] += d[i - 3][0];
                d[i][1] += d[i - 3][1];
            }
            if (i >= 4)
                d[i][1] += d[i - 4][1];
            d[i][0] %= mod;
            d[i][1] %= mod;
        }
        long long ans = 1;
        for (int i = 0; i < pressedKeys.size(); i++) {
            int cnt = 1;
            while (i < pressedKeys.size() - 1 && pressedKeys[i + 1] == pressedKeys[i]) {
                ++i;
                cnt++;
            }
            if (pressedKeys[i] == '7' || pressedKeys[i] == '9')
                ans *= d[cnt][1];
            else
                ans *= d[cnt][0];
            ans %= mod;
        }
        return ans;
    }
};