#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REG register
#define For(a,b,c) for(REG int (a) = (b); (a) <=c ; ++a)

int n, T;
ll mx[5], a, ans, H;

int main()
{
    T = 1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %lld", &n, &H);
        mx[0] = mx[1] = mx[2] = 0;
        For(i, 1, n) {
            scanf("%lld", &a);
            mx[0] = a;
            sort(mx, mx + 3);
        }
        if (n == 1) ans = (H - 1) / a + 1;
        else {
            ll cost = mx[1] + mx[2];
            ans = 2 * (H / cost);
            H %= cost;
            if (H > 0 && H <= mx[2]) ++ans;
            else if (H > mx[2]) ans += 2;
        }
        printf("%lld\n", max(ans, 1ll));
    }
    return 0;
}