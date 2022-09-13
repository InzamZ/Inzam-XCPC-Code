#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m1, m2, ans = 3, v;
string s;

signed main() {
    srand(time(0));
    int l = 1, r = 2;
    for (int i = 1; i <= 25; ++i) {
        cout << "? " << l << ' ' << r << endl ;
        fflush(stdout);
        cin >> m1;
        cout << "? " << r << ' ' << l << endl ;
        fflush(stdout);
        cin >> m2;
        v = min(m1, m2);
        if (v == -1)
            break;
        if (m1 != m2) {
            ans = max(ans, m1 + m2);
            break;
        }
        else {
            ans = max(ans, r);
            if (l + 1 < r)
                l++;
            else ++r;
        }
    }
    cout << "! " << ans << '\n';
    fflush(stdout);
    return 0;
}