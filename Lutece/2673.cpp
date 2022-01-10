#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 1e6 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll mod = 1e9 + 7;

int prinum[maxn], vis[maxn];
ll F_Euler[maxn];
void Pre()
{
    vis[1] = F_Euler[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        if (vis[i] == 0) {
            prinum[++(*prinum)] = i;
            F_Euler[i] = i - 1;
        }
        for (int j = 1; j <= (*prinum) && i * prinum[j] < maxn; ++j) {
            vis[i * prinum[j]] = 1;
            if (i % prinum[j] == 0) {
                F_Euler[i * prinum[j]] = prinum[j] * F_Euler[i];
                break;
            }
            else
                F_Euler[i * prinum[j]] = F_Euler[prinum[j]] * F_Euler[i];
        }
    }
    for (int i = 2; i < maxn; ++i) {
        F_Euler[i] *= i;
        F_Euler[i] %= mod;
        F_Euler[i] *= F_Euler[i - 1];
        F_Euler[i] %= mod;
    }
}

int main()
{
    int T = 1, n;
    ll ans = 0;
    scanf("%d", &T);
    Pre();
    while (T--) {
        ans = 1;
        scanf("%d", &n);
        printf("%lld\n", F_Euler[n] % mod);
    }
    return 0;
}