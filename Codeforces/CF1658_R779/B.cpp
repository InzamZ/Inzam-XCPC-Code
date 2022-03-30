//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("/out.txt" , "w", stdout);
const int maxn = 1e5 + 10;
int T = 1, n;
ll ans = 0;
int main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 1;
        cin >> n;
        if (n % 2 == 1)
            ans = 0;
        else {
            for (int i = 1; i <= n / 2; ++i) {
                ans *= (i*i);
                ans %= 998244353;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}