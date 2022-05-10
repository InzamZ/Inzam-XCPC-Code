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
vector<int>a;
int s[maxn];
signed main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n >> m;
        a.clear();
        for (int i = 1; i <= n; i++) {
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        int cnt = 1;
        s[0] = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] <= 0)
                break;
            s[cnt] = s[cnt - 1] + a[i];
            cnt++;
        }
        s[cnt] = 0;
        for (int i = 0; i < m; ++i) {
            cin >> x;
            if (x > s[cnt - 1])
                cout << "-1\n";
            else
                cout << lower_bound(s, s + cnt, x) - s << '\n';
        }
    }
    return 0;
}