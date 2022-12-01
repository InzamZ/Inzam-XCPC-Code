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

class Solution {
public:
    int temperatureTrend(vector<int>& temperatureA, vector<int>& temperatureB) {
        for (int i = 1; i < temperatureA.size(); ++i)
        {
            if (temperatureA[i] > temperatureA[i-1]) temperatureA[i-1] = 1;
            else if (temperatureA[i] == temperatureA[i-1]) temperatureA[i-1] = 0;
            else temperatureA[i-1] = -1;
            if (temperatureB[i] > temperatureB[i-1]) temperatureB[i-1] = 1;
            else if (temperatureB[i] == temperatureB[i-1]) temperatureB[i-1] = 0;
            else temperatureB[i-1] = -1;
            temperatureA[i-1] = temperatureA[i-1] - temperatureB[i-1];
        }
        int ans = 0,res = 0;
        for (int i = 1; i < temperatureA.size(); ++i)
        {
            if (temperatureA[i-1] == 0) res++;
            else res = 0;
            ans = max(ans,res);
        }
        return ans;
    }
};