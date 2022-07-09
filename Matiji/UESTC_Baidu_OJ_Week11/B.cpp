#include<bits/stdc++.h> 

#define int long long
using namespace std;
int dp[1050][2], sum = 0, ans1 = 0, ans2 = 0, n;

signed main( )
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= 1000; ++j) dp[j][(i+1)%2] = 0;
        if (i == 0) dp[0][0] = 1;
        for (int j = 0; j <= 1000; ++j){
            dp[j+4][(i+1)%2] += dp[j][i%2];
            dp[j+1][(i+1)%2] += dp[j][i%2];
            dp[j+2][(i+1)%2] += dp[j][i%2];
            dp[j+3][(i+1)%2] += dp[j][i%2];
        }
    }
    for (int j = 0; j <= 1000; ++j){
        sum += dp[j][n%2];
        if (j < 2 * n) ans1 += dp[j][n%2];
        if (j > 3 * n) ans2 += dp[j][n%2];
    }
    int igcd = __gcd(ans1, sum);
    cout << ans1/igcd << '/' << sum/igcd << endl;
    igcd = __gcd(ans2, sum);
    cout << ans2/igcd << '/' << sum/igcd << endl;
    return 0;
}