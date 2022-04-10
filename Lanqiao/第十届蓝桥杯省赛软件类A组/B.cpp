//InzamZ
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<int,int>
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("/out.txt" , "w", stdout);
const int maxn = 3e7 + 10;
int T = 1, n, ans = 0;
int f[maxn];
int main()
{
    FIO;
    // cin >> T;
    T = 20190324;
    f[1] = f[2] = f[3] = 1;
    for (int i = 4; i <= T; ++i) {
        f[i] = (f[i - 1] + f[i - 2] + f[i - 3])%10000;
    }
    printf("%04d\n", f[T]);
    return 0;
}