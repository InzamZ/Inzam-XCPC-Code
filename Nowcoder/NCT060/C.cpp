//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, sum, ans = 0;
int a[maxn];
int main()
{
    FIO;
    cin >> T;
    while (T--) {
        sum = ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum |= a[i];
        }
        for (int i = 0; i < n; i++)
            ans ^= (a[i] & sum);
        cout << ans << '\n';
    }
    return 0;
}