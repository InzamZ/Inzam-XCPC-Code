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
    int giveGem(vector<int> &gem, vector<vector<int>> &operations)
    {
        int ans = 0, imx = -1, imn = 1e9;
        for (int i = 0; i < operations.size(); ++i) {
            gem[operations[i][1]] += gem[operations[i][0]] / 2;
            gem[operations[i][0]] /= 2;
        }
        for (int i = 0; i < gem.size(); ++i) {
            if (i == 0) {
                imx = gem[i];
                imn = gem[i];
            }
            else {
                if (gem[i] > imx)
                    imx = gem[i];
                if (gem[i] < imn)
                    imn = gem[i];
            }
        }
        printf("%d\n", imx - imn);
        return imx - imn;
    }
};
