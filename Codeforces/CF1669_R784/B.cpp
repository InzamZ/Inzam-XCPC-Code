//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("/out.txt" , "w", stdout);
const int maxn = 2e5 + 10;
int T = 1, n, ans = 0, k;

int cnt[maxn];
int main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = -1;
        cin >> n;
        for (int i = 0; i <= n; ++i)
            cnt[i] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> k;
            cnt[k]++;
            if (cnt[k] >= 3)
                ans = k;
        }
        cout << ans << '\n';
    }
    return 0;
}