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
int T = 1, n, ans = 0, p;
int c[maxn], cnt[maxn];
int main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 1;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> c[i];
        for (int i = 0; i < n; ++i) {
            if (c[i] == 1)
                p = i;
            if (c[i] <= n)
                ++cnt[c[i]];
        }
        rotate(c, c + p, c + n);
        if (cnt[1] != 1)
            ans = 0;
        for (int i = 1; i < n; ++i) {
            if (c[i] - c[i - 1] > 1) {
                ans = 0;
                break;
            }
        }
        if (ans)
            cout << "Yes\n";
        else
            cout << "No\n";
        for (int i = 1; i <= n; ++i)
            cnt[i] = 0;
    }
    return 0;
}