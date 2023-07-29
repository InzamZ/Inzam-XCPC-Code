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
const int maxn = 20;
const int maxb = 110;
int T = 1, n, ans = 0;
int main()
{
    FIO;
    srand(time(0));
    n = 1ll * rand() * rand() % maxn + 1;
    // n = rand() % 10 + 1;
    int m = rand() % maxn + 1;
    cout << n << '\n';
    for (int i = 1; i <= n; ++i)
        cout << 1ll * rand() * rand() % maxn + 1 << ' ' << 1ll * rand() * rand() % maxn + 1 << '\n';
    cout << m << '\n';
    for (int i = 1; i <= m; ++i)
        cout << 1ll * rand() * rand() % maxn + 1 << '\n';
    return 0;
}