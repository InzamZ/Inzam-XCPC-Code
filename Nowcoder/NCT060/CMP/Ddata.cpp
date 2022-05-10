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
int T = 1, n, ans = 0, m;
int main()
{
    FIO;
    srand(time(0));
    n = rand() % 10000000 + 1;
    m = rand() % 10000000 + 1;
    if (n > m)
        swap(n, m);
    // n = rand() % 10 + 1;
    cout << 1 << '\n';
    cout << n << ' ' << m << '\n';
    return 0;
}