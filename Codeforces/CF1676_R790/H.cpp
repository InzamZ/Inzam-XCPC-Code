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
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0;
int ta[maxn];

int lowbit(int x)
{
    return x & (-x);
}

void update(int i, int val)
{
    int x = i;
    while (i <= n) {
        ta[i] += val;
        i += lowbit(i);
    }
}

int getsum(int i)
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
    // FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> x;
            ans += getsum(n) - getsum(x - 1);
            update(x, 1);
        }
        for (int i = 0; i <= n; ++i)
            ta[i] = 0;
        cout << ans << '\n';
    }
    return 0;
}