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
    int res = -1ll * 0x3fffffffffffffff, x = i;
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
        string s;
        cin >> n >> s;
        int l = -1, x = 0, y = 0;
        for (int i = 0 ; i < n; i += 2)
        {
            if (s[i] != s[i + 1])
            {
                ++x;
            }
            else 
            {
                if (l != s[i]) ++y;
                l = s[i];
            }
        }
        cout << x << ' ' << max(y, 1ll) << endl;
    }
    return 0;
}