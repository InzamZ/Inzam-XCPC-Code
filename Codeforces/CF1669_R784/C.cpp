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
int T = 1, n, ans = 0;

int a[maxn];
int main()
{
    FIO;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        ans = 1;
        for (int i = 2; i < n; ++i)
            if ((a[i] & 1) != (a[i - 2] & 1)) {
                ans = 0;
                break;
            }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}