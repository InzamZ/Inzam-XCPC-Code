//InzamZ
//
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define forr(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0)
#define FFFOUT freopen("./out.txt" , "w", stdout)
#define FFFIN freopen("./in.txt" , "r", stdin)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, x, ans = 0;
signed main()
{
    // FIO;
    cin >> T;
    while (T--) {
        ans = 0;
        int a, b, c;
        scanf("%1d%1d%1d", &a, &b, &c);
        ans = a + b + c;
        scanf("%1d%1d%1d", &a, &b, &c);
        if (ans == a + b + c)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}