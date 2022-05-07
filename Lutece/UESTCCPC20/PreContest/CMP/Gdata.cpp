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
int T = 1, n, ans = 0;
int main()
{
    FIO;
    srand(time(0));
    n = rand() % 1000000 + 1;
    // n = rand() % 10 + 1;
    int m = 1;
    cout << n << ' ' << m << '\n';
    for (int i = 1; i <= n; ++i)
        cout << rand() % n << ' ';
    int l, r;
    l = rand() % n + 1;
    r = rand() % n + 1;
    if (l > r)
        swap(l, r);
    cout << '\n' << l << ' ' << r << '\n';
    return 0;
}