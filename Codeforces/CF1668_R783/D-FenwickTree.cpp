//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

#define int long long

#define pii pair<int,int>
#define pll pair<ll,ll>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, ans = 0;

int fenwick[maxn];
int dp[maxn], idx[maxn], pre[maxn];
vector<int>v;
int lowbit(int x)
{
    return x & (-x);
}

void update(int i, int val)
{
    int x = i;
    while (i <= n) {
        fenwick[i] = max (fenwick[i], val);
        i += lowbit(i);
    }
}

int getmax(int i)
{
    int res = 0, x = i;
    while (i > 0) {
        res = max(res, fenwick[i]);
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
        pre[0] = 0;
        v.clear();
        for (int i = 0; i <= n; i++)
            fenwick[i] = -1ll * 0x3fffffffffffffff;
        for (int i = 1; i <= n; i++) {
            cin >> idx[i];
            pre[i] = pre[i - 1] + idx[i];
            v.push_back(pre[i]);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 1; i <= n; i++)
            idx[i] = lower_bound(v.begin(), v.end(), pre[i]) - v.begin() + 1;
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = 0;
            if (pre[i] - pre[i - 1] > 0)
                dp[i] = 1;
            if (pre[i] - pre[i - 1] < 0)
                dp[i] = -1;
            dp[i] = max(dp[i - 1], getmax(idx[i]) + i);
            if (pre[i] > 0)
                dp[i] = i;
            update(idx[i], dp[i] - i);
        }
        cout << dp[n] << '\n';
    }
    return 0;
}