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
    // cin >> T;
    T = 2019;
    for (int i = 1; i <= T; ++i) {
        int tmp = i;
        while (tmp) {
            if (tmp % 10 == 1 || tmp % 10 == 2 || tmp % 10 == 0 || tmp % 10 == 9) {
                ans += i * i;
                break;
            }
            tmp /= 10;
        }
    }
    cout << ans << '\n';
    return 0;
}