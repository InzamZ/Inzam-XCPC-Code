#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
using ll = long long;
const ll mod = 998244353;

ll a[maxn], ans = 0, sum = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ans += ((a[i] * a[i]) % mod);
        ans %= mod;
    }
    sort(a, a + n);
    sum = a[n - 1];
    for (int i = n - 2; i >= 0 ; --i) {
        ans = ans + sum * a[i] % mod;
        ans %= mod;
        sum = sum * 2 + a[i];
        sum %= mod;
    }
    cout << ans << endl;
    return 0;
}