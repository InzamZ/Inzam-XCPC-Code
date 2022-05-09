//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
#define int long long

#define pii pair<int,int>
#define forr(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e3 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0;
int p[maxn];
int at[maxn], bt[maxn], sa[maxn], sb[maxn][maxn];

int lowbit(int x)
{
    return x & (-x);
}

void update(int i, int val, int *ta)
{
    int x = i;
    while (i <= n) {
        ta[i] += val;
        i += lowbit(i);
    }
}

int getsum(int i, int *ta)
{
    int res = 0, x = i;
    while (i > 0) {
        res += ta[i];
        i -= lowbit(i);
    }
    return res;
}

signed main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n;
        bt[n + 1] = 0;
        forr(i, 1, n) {
            cin >> p[i];
            bt[i] = 0;
            // update(i, 1, at);
            // sa[i] = getsum(i - 1, at) + sa[i - 1];
        }
        for (int i = n; i >= 1; i--) {
            update(p[i], 1, bt);
            sb[i][i] = 0;
            for (int j = i - 1; j >= 1; j--) {
                sb[j][i] = getsum(p[j] - 1, bt);
                sb[j][i] += sb[j + 1][i];
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++) {
                if (p[i] >= p[j])
                    continue;
                else
                    ans += sb[i + 1][j + 1] - sb[j][j + 1];
            }
        forr(i, 0, n) {
            forr(j, 0, n) {
                sb[i][j] = 0;
            }
            // update(i, 1, at);
            // sa[i] = getsum(i - 1, at) + sa[i - 1];
        }
        cout << ans << '\n';
    }
    return 0;
}