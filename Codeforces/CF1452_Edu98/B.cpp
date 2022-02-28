//InzamZ

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
multiset<ll>s;
int main()
{
    int t;
    cin >> t;
    while (t--) {
        s.clear();
        long long sum = 0, all = 0, num;
        ll ans = 0, mx = 0, n;
        scanf ("%lld", &n);
        for (int i = 1; i <= n; i++) {
            scanf ("%lld", &num);
            s.insert(num);
            mx = max(mx, num);
            sum += num;
        }
        for (set<ll>::iterator it = s.begin(); it != s.end(); ++it)
            all += (mx - (*it));
        ans = all - mx;
        if (ans <= 0)
            ans = 0;
        if ((ans + sum) % (n - 1) == 0)
            cout << ans << endl;
        else
            cout << ans + (n - 1 - ((sum + ans) % (n - 1))) << endl;
    }
    return 0;
}