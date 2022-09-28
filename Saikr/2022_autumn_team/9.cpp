#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define REG register
#define FREAD 1
#define FIO std::ios::sync_with_stdio(false);\
            std::cin.tie(0);
#define FFF freopen("/out.txt" , "w", stdout);

const int maxn = 1e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;
const ll mod = 998244353;

int T = 1, n, ans = 0;

bool vis[maxn], pic[maxn];
ll a[maxn];
vector<int>v;

void solve(int n) {
    for (int i = 1; i * i <= n; ++i) {
        pic[0] = 0;
        for (int j = 1; j < i; ++j) {
            pic[j] = pic[j - 1];
            if (__gcd(i, j) == 1)
                pic[j]++;
        }
        int x = n % i;
        int y = (n - x) / i;
        ans = (ans + 1ll * (y - 1) * pic[i - 1] + pic[x]) % mod;
    }
    cout << ans * 2 << '\n';
}

int main() {
    // FIO;
    // read(T);
    for (int i = 2; i * i <= 1e7; ++i) {
        if (!vis[i])
            v.push_back(i);
        for (int j = i * 2; j * j <= 1e7; j += i)
            vis[j] = 1;
    }
    while (T--) {
        ans = 0;
        cin >> n;
        solve(n);
    }
    return 0;
}