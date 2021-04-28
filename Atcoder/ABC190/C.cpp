#include <iostream>
#include <cmath>

const int maxn = 110;
int a[maxn], b[maxn], c[maxn], d[maxn];
bool exi[maxn];

using ll = long long;

int main()
{
    int m, n, k, ans = 0, cnt = 0;
    ll p, op;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
        std::cin >> a[i] >> b[i];
    std::cin >> k;
    p = (1 << k);
    for (int i = 0; i < k; i++)
        std::cin >> c[i] >> d[i];
    for (ll i = 0; i < p; i++) {
        cnt = 0;
        for (int j = 1; j <= m; j++)
            exi[j] = false;
        for (int j = 0, op = i; j < k; j++, op >>= 1) {
            if (op & 1ll )
                exi[c[j]] = true;
            else
                exi[d[j]] = true;
        }
        for (int j = 0; j < m; j++) {
            if (exi[a[j]] && exi[b[j]])
                cnt++;
        }
        ans = std::max(ans, cnt);
    }
    std::cout << ans << std::endl;
    return 0;
}

