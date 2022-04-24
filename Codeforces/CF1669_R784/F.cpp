//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("/out.txt" , "w", stdout);
const int maxn = 1e6 + 10;
int T = 1, n, ans = 0;
int can[maxn];
int main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> can[i];
        int l = 1, r = n, cnt = 0;
        ll a = 0, b = 0;
        while (l <= r) {
            if (a == b) {
                ans = cnt;
                a += can[l++];
                cnt++;
            }
            else if (a < b) {
                a += can[l++];
                cnt++;
            }
            else {
                b += can[r--];
                cnt++;
            }
        }
        if (a == b)
            ans = n;
        cout << ans << '\n';
    }
    return 0;
}