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
const int maxn = 1e6 + 10;
const int maxb = 110;
ll T = 1, n, ans = 0, m;
ll a[maxn];
int main()
{
    long long l, r;
    vector<int>v;
    scanf ("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf ("%lld", &a[i]);
    cin >> l >> r;
    v.push_back(n);
    v.push_back(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (l <= i && i <= r)
            continue;
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    cout << v[1] << endl;
    return 0;
}