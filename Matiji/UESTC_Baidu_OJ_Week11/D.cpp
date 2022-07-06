#include<bits/stdc++.h>

#define int long long
using namespace std;
int n, p;
int inv[4000000];

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n >> p;
    inv[0] = inv[1] = 1;
    for (int i = 2; i <= n; ++i)
        inv[i] = inv[p % i] * (p - p / i) % p;
    for (int i = 1; i <= n; ++i)
        cout << inv[i] << '\n';
    return 0;
}