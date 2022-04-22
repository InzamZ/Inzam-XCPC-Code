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
int main()
{
    FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        cin >> n;
        if (n < 1400) cout << "Division 4\n";
        if (1400 <= n && n < 1600) cout << "Division 3\n";
        if (1600 <= n && n < 1900) cout << "Division 2\n";
        if (1900 <= n) cout << "Division 1\n";
    }
    return 0;
}