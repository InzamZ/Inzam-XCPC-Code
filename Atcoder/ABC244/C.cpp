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
int T = 1, n, ans = 0;
bool flag[maxn];
int main()
{
    // FIO;
    // cin >> T;
    while (T--) {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n + 1; ++i) {
            if (i != 1) {
                fflush(stdout);
                cin >> ans;
                flag[ans] = true;
            }
            for (int j = 1; j <= 2 * n + 1; ++j) {
                if (!flag[j]) {
                    cout << j << '\n';
                    flag[j] = true;
                    break;
                }
            }
        }
    }
    return 0;
}