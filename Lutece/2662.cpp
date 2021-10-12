#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define F(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define f(a,b,c) for(int (a)=(b);(a)>=(c);--(a))

const int maxn = 5e5 + 10;
const int maxb = 110;
const int inf = 1e9;
const ll Inf = 1e18;

int prinum[maxn], vis[maxn], F_Euler[maxn], F_Mobius[maxn];
int F_Cnt[maxn], pricnt[maxn], F_Sum[maxn], sum[maxn];
int F[maxn], mn[maxn], mnpow[maxn];
void Pre()
{
    vis[1] = F_Mobius[1] = F_Euler[1] = F_Cnt[1] = sum[1] = F_Sum[1] = F[1] = 1;
    mn[1] = 0;
    for (int i = 2; i < maxn; ++i) {
        if (vis[i] == 0) {
            prinum[++(*prinum)] = i;
            F_Euler[i] = i - 1;
            F_Mobius[i] = -1;
            pricnt[i] = 1;
            F_Cnt[i] = 2;
            F_Sum[i] = sum[i] = i + 1;
            F[i] = F_Sum[i] - (i - 1);
            mn[i] = 1;
            mnpow[i] = i;
        }
        for (int j = 1; j <= (*prinum) && i * prinum[j] < maxn; ++j) {
            vis[i * prinum[j]] = 1;
            if (i % prinum[j] == 0) {
                F_Euler[i * prinum[j]] = prinum[j] * F_Euler[i];
                F_Mobius[i * prinum[j]] = 0;
                pricnt[i * prinum[j]] = pricnt[i] + 1;
                F_Cnt[i * prinum[j]] = F_Cnt[i] / pricnt[i * prinum[j]] * (pricnt[i * prinum[j]] + 1);
                sum[i * prinum[j]] = prinum[j] * sum[i] + 1;
                F_Sum[i * prinum[j]] = F_Sum[i] / sum[i] * sum[i * prinum[j]];
                mn[i * prinum[j]] = mn[i] + 1;
                mnpow[i * prinum[j]] = mnpow[i] * prinum[j];
                F[i * prinum[j]] = F[i / mnpow[i]] * (F_Sum[mnpow[i * prinum[j]]] - (prinum[j] - 1) * F_Sum[mnpow[i * prinum[j]] / prinum[j]]);
                break;
            }
            else {
                F_Euler[i * prinum[j]] = F_Euler[prinum[j]] * F_Euler[i];
                F_Mobius[i * prinum[j]] = -F_Mobius[i];
                F_Cnt[i * prinum[j]] = F_Cnt[i] * 2;
                pricnt[i * prinum[j]] = 1;
                F_Sum[i * prinum[j]] = F_Sum[prinum[j]] * F_Sum[i];
                sum[i * prinum[j]] = 1 + prinum[j];
                mn[i * prinum[j]] = 1;
                mnpow[i * prinum[j]] = prinum[j];
                // F[i * prinum[j]] = F[i] * (F_Cnt[prinum[j]] - (prinum[j] - 1) * F_Cnt[1]);
                F[i * prinum[j]] = F[i] * F[prinum[j]];
            }
        }
    }
}

int main()
{
    int T = 1, n, ans = 0;
    // scanf("%d", &T);
    Pre();
    while (T--) {
        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            printf("%d%c", F_Euler[i], i == n ? '\n' : ' ');
        for (int i = 1; i <= n; ++i)
            printf("%d%c", F_Mobius[i], i == n ? '\n' : ' ');
        for (int i = 1; i <= n; ++i)
            printf("%d%c", F_Cnt[i], i == n ? '\n' : ' ');
        for (int i = 1; i <= n; ++i)
            printf("%d%c", F_Sum[i], i == n ? '\n' : ' ');
        for (int i = 1; i <= n; ++i)
            printf("%d%c", F[i], i == n ? '\n' : ' ');
    }
    return 0;
}