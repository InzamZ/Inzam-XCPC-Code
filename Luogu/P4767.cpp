#include <bits/stdc++.h>
using namespace std;

#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))
#define INF 0x3f3f3f3f

const int maxv = 3010;
const int maxp = 310;
using ll = long long;

int x[maxv], dp[maxv][maxp], d[maxv][maxp], w[maxv][maxv];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int V, P;
    cin >> V >> P;
    memset(dp, 0x3f, sizeof(dp));
    F(i, 1, V)    cin >> x[i];
    sort(x + 1, x + 1 + V);
    F(l, 1, V) {
        w[l][l] = 0;
        F(r, l + 1, V) {
            w[l][r] = w[l][r - 1] + x[r] - x[(l + r) >> 1];
        }
    }
    dp[0][0] = 0;
    F(j, 1, P) {
        d[V + 1][j] = V;
        f(i, V, 1) {
            int mind, mindp = INF;
            F(k, d[i][j - 1], d[i + 1][j]) {
                if (dp[k][j - 1] + w[k + 1][i] < mindp) {
                    mindp = dp[k][j - 1] + w[k + 1][i];
                    mind = k;
                }
            }
            dp[i][j] = mindp;
            d[i][j] = mind;
        }
    }
    cout << dp[V][P] << endl;
    return 0;
}