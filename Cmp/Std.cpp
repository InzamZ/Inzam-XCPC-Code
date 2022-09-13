#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, k, ans = 0, a[maxn], b[maxn], c[maxn];
vector<int>v;
signed main()
{
#ifdef ONLINE_JUDGE //don't mix cin/scanf, cout/printf!
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
#endif
	freopen("./data.input","r",stdin);
	freopen("./std.output","w",stdout);
    ans = 2, k = 0;
    cin >> n;
    for (int i = 1; i <= n ; ++i)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    n = unique(a + 1, a + 1 + n) - a - 1;
    for (int i = 1; i <= n ; ++i) {
        if (a[i] % 2 != a[1] % 2)
            break;
        if (i == n)
            ans = 1;
    }
    int res = a[2] - a[1];
    for (int i = 2; i <= n ; ++i)
        res = __gcd(res, a[i] - a[1]);
    if (res >= 2)
        ans = 1;
    cout << ans << endl;
    return 0;
}