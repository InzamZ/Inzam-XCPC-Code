// Created on Inzam的iPad.

#include <iostream>
#include <map>
#include <queue>
using namespace std;

#define maxn 10010
string s1,s2;
int n, ans = 0, id = 1;
long long sum[maxn], val[maxn],dp[maxn];

int main() {
    cin >> n;
    sum[0] = 0;
    for (int i = 1 ; i <= n; ++i)
    {
        cin >> val[i];
        sum[i] = sum[i - 1] + val[i];
    }
    dp[1] = 0;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = i - 1; j >= 1; --j)
        {
            int len = i - j - 1;
            long long res = 0;
            if (len & 1) 
            {
                res = sum[len/2] * 2 + val[len/2+1];
            }
            else res = sum[len/2] * 2;
            // cout << "j: " << j << "dp[j]" << dp[j] << "res: " << res << "dp[i]" <<dp[i] << endl;
            dp[i] = max(dp[i],dp[j] + res);
        }
    }
    // cout << dp[n] << endl;
    for (int i = n - 1; i >= 1; --i)
    {
        int len = n - i;
        long long res = 0;
        if (len & 1) 
        {
            res = sum[len/2] * 2 + val[len/2+1];
        }
        else res = sum[len/2] * 2;
        dp[n] = max(dp[n] , dp[i] + res);
    }
    cout << dp[n] << endl;
    return 0;
}