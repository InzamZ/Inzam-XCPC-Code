#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
using ll=long long;

ll dp[maxn][5],ans=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    dp[2][0]=dp[2][1]=dp[2][2]=dp[2][3]=1;
    for (int i=3;i<=n;i++)
    {
        ans=ans*2+dp[i-1][0]+dp[i-1][3];
        dp[i][0]=dp[i-1][1];
        dp[i][1]=dp[i-1][2]+dp[i-1][3];
        dp[i][2]=dp[i-1][0]+dp[i-1][1];
        dp[i][3]=dp[i-1][2];
    }
    printf("%lld\n",ans);
    return 0;
} 