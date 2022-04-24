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
int T = 1, n, ans = 0, k;
int cnt[50];
int main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n >> k;
        for (int i = 0; i <= 30; ++i)
            cnt[i] = 0;
        for (int i = 1; i <= n; ++i) {
            int num, idx = 0;
            cin >> num;
            while (num) {
                cnt[idx++] += (num % 2);
                num /= 2;
            }
        }
        for (int i = 30; i >= 0; --i) {
            if (cnt[i] + k >= n) {
                k -= (n - cnt[i]);
                ans |= (1 << i);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}