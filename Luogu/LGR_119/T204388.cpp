#include <bits/stdc++.h>
using namespace std;

#define int long long
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, ans = 0, tmp = 0, a[maxn], b[maxn];
signed main()
{
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i){
        cin >> b[i];
        if (a[i] != b[i]) ++ans;
    }
    reverse(a+1,a+1+n);
    for (int i = 1; i <= n; ++i)
        if (a[i] != b[i]) ++tmp;
    cout << min(ans,tmp + 1) << '\n';
    return 0;
}