#include <bits/stdc++.h>
using namespace std;
#define maxn 300010
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))
#define INF 0x3f3f3f3f
#define mod 100000007 
using ll = long long;

ll w[maxn],v[maxn],dp[maxn];

int main()
{
    ios::sync_with_stdio(false);
    int T, n, m;
    cin >> T;
    while (T--) {
        cin >> n >>m;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= 4; j++) {
                cin>>w[j]>>v[j];
            }
            for (int j = m; j >= 1; --j) {
                for (int k = 1;k <= 4;++k)
                {
                    if (j < w[k]) break;
                    dp[j] = max(dp[j-w[k]]+v[k],dp[j]);
                }
            }
        }
        cout<<dp[m]<<'\n';
        for (int j = m; j >= 0; --j) dp[j]=0;
    }
    return 0;
}