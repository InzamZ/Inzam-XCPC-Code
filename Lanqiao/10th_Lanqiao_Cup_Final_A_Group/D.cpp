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
int T = 1, n;
ll f[maxn],ans = 0;

//1 2 3 4 6 9 12 24 36

bool isPrime(ll x)
{
    for (ll i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    // 1*2 = 2
    // 1*2*2 = 4 : 1 2 4
    // 1*2*3 = 6 : 1 2 | 3 6
    // 1*2*3*2 = 12 : 1 2 3 | 4 6 12
    // 1*2*3*4 = 24 : 1 2 3 4 6 8 12 24
    // 1*2*2*2 = 8
    // 1*2*2*2*2 = 16
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= 60; ++i) {
        if (i % 2)
            f[i] = f[(i + 1) / 2] * f[(i + 1) / 2];
        else {
            f[i] = f[i / 2];
            for (int j = 2;; ++j) {
                if (!isPrime(j))
                    continue;
                if (f[i] % j == 0)
                    continue;
                f[i] *= j;
                break;
            }
        }
    }
    for (int i = 1; i <= 60; ++i) {
        ans += f[i];
		cout << i << " " << f[i] << '\n';
    }
	cout << "ans :" << ans << '\n';
    return 0;
}